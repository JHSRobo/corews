#!/bin/bash

# Check sudo perms
if [[ "$(id -u)" != 0 ]]
  then echo "Please run as root"
  exit
fi

# Install helpful packages
apt install gcc make perl curl pip wget gnupg -y
pip install setuptools==58.2.0

# Add helpful stuff to ~/.bashrc
echo "source /opt/ros/humble/setup.bash" >> /home/jhsrobo/.bashrc
echo "source /home/jhsrobo/corews/install/setup.bash" >> /home/jhsrobo/.bashrc
echo "alias topside=\"ros2 launch core topside.yaml\"" >> /home/jhsrobo/.bashrc

# Add Network Shortcuts
echo "192.168.1.100 master" >> /etc/hosts
echo "192.168.1.110 opside" >> /etc/hosts
echo "192.168.1.111 bottomside" >> /etc/hosts

# Install ROS
curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
apt update
apt install ros-humble-desktop ros-dev-tools -y
rosdep init
sudo -u jhsrobo rosdep update

# Install GitHub cli tools
type -p curl >/dev/null || (sudo apt update && sudo apt install curl -y)
curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | sudo dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg
sudo chmod go+r /usr/share/keyrings/githubcli-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | sudo tee /etc/apt/sources.list.d/github-cli.list > /dev/null
apt update
apt install gh -y

# Install Gazebo Simulation
wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
apt update
apt install ignition-fortress -y

# Call the update script
sudo bash /home/jhsrobo/corews/scripts/tcu/tcu_update.bash
