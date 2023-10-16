#!/bin/bash

# Check sudo perms
if [[ "$(id -u)" != 0 ]]
  then echo "Please run as root"
  exit
fi

# Update the corews
git pull --hard

# Remove previously compiled code
rm -rf /home/jhsrobo/corews/build
rm -rf /home/jhsrobo/corews/install
rm -rf /home/jhsrobo/corews/log

cd /home/jhsrobo/corews/src

# Remove old packages
rm -rf thruster_interface gpio_interface sensor_interface

# Clone new packages
git clone https://github.com/JHSRobo/thruster_interface
git clone https://github.com/JHSRobo/gpio_interface
git clone https://github.com/JHSRobo/sensor_interface

# Update dependencies
sudo -u jhsrobo rosdep update
sudo -u jhsrobo rosdep install --from-paths src --ignore-src --rosdistro=${ROS_DISTRO} -y --os=ubuntu:jammy

# Compile and source
cd /home/jhsrobo/corews
sudo -u jhsrobo colcon build
source install/setup.bash

# Give jhsrobo ownership of the workspace
sudo chown jhsrobo: -R /home/jhsrobo/corews