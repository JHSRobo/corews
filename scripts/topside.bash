# This script launches the topside ROS2 instance.
# Part of the CORE ROV system

# This command sources our ROS2 overlay
source /home/jhsrobo/corews/install/setup.bash

# This command executes the ROS Launch File (which actually runs our code)
ros2 launch core topside.yaml
