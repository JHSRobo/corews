#!/bin/bash

# Check sudo perms
if [[ "$(id -u)" != 0 ]]
  then echo "Please run as root"
  exit
fi

# Update the corews
git pull --hard

cd /home/jhsrobo/corews/src

# Remove old packages
rm -rf motion_control rov_sim

# Clone new packages
git clone https://github.com/JHSRobo/motion_control
git clone https://github.com/JHSRobo/rov_sim

# Update dependencies
sudo -u jhsrobo rosdep install --from-paths src --ignore-src --rosdistro=${ROS_DISTRO} -y --os=ubuntu:jammy

# Compile and source
cd /home/jhsrobo/corews
colcon build
source install/setup.bash

# Give jhsrobo ownership of the workspace
sudo chown jhsrobo: -R /home/jhsrobo/corews
