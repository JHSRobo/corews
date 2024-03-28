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
rm -rf img_capture_2024
rm -rf ops_tools

# Give jhsrobo ownership of the workspace
sudo chown jhsrobo: -R /home/jhsrobo/corews

# Clone new packages
git clone https://github.com/JHSRobo/img_capture_2024
git clone https://github.com/JHSRobo/ops_tools

# Update dependencies
sudo -u jhsrobo rosdep install --from-paths src --ignore-src --rosdistro=${ROS_DISTRO} -y --os=ubuntu:jammy

cd ~
colcon build --symlink-install
