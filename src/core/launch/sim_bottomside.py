import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Set up arguments from parameters file
    # Used for running rviz
    rviz_config_path = '/home/jhsrobo/corews/src/core/rviz_config.rviz'

    # Get the URDF File as a description to be used later.
    urdf_file_name = 'rov.urdf.xml'
    urdf = os.path.join(
        get_package_share_directory('rov_sim'),
        urdf_file_name)
    with open(urdf, 'r') as infp:
        robot_desc = infp.read()

    return LaunchDescription([

        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),
        
        DeclareLaunchArgument(
            'rvizconfig',
            default_value=str(rviz_config_path),
            description='Absolute path to rviz config file'), 

        # Package for detailing robot data (Not custom written)
        # Uses URDF File
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time, 'robot_description': robot_desc}],
            arguments=[urdf]),

        # Launches a GUI that lets you control joint states
        # (Movable Parts)
        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher'),

        # Package for some basic ROV States
        Node(
            package='rov_sim',
            executable='state_publisher',
            name='state_publisher',
            output='screen'),
        
        # Package for simulating GPIO Toggle
        Node(
            package='rov_sim',
            executable='gpio_control',
            name='gpio_control'),

        # Package for simulating depth sensor
        Node(
            package='rov_sim',
            executable='depth_sensor',
            name='depth_sensor'),

        # Launch the Robot Visualizer GUI
        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            output='screen',
            arguments=['-d', LaunchConfiguration('rvizconfig')],       
        ),
    ])