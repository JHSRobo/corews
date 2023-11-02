import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Set up arguments from parameters file
    # Used for running rviz
    rviz_config_path = '/home/jhsrobo/corews/src/rov_sim/rviz_config.rviz'

    # Get the URDF File as a description to be used later.
    urdf_file_name = 'rov.urdf.xml'
    urdf = os.path.join(
        get_package_share_directory('rov_sim'),
        urdf_file_name)
    
    # Get the SDF File as a description to be used later.
    sdf_file_name = 'rov_sim.sdf'
    sdf = os.path.join(
        get_package_share_directory('rov_sim'),
        sdf_file_name)

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

        DeclareLaunchArgument(
            'sdf_path',
            default_value=str(sdf),
            description='Path to .sdf file'),

        # Package for detailing robot data (Not custom written)
        # Uses URDF File
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time, 'robot_description': robot_desc}],
            arguments=[urdf]),

        # Run Ignition Gazebo
        ExecuteProcess(
            cmd=['ign gazebo', LaunchConfiguration('sdf_path')],
            output='screen',
            shell=True ),

        # Launch ROS Ignition Gazebo Bridge
        Node(
            package='ros_gz_bridge',
            executable='parameter_bridge',
            # Bridge our cmd_vel topic to the cmd_vel topic of the Ignition Simulation
            arguments=['/cmd_vel@geometry_msgs/msg/Twist]ignition.msgs.Twist'],
            output='screen'),

        # Launch Gazebo
        ExecuteProcess(
            cmd=["ign service -s /world/orca_sim/create --reqtype ignition.msgs.EntityFactory --reptype ignition.msgs.Boolean \
                 --timeout 1000 --req 'sdf_filename: \"/home/jhsrobo/corews/src/rov_sim/urdf/rov.urdf.xml\", name: \"orca\"'"],
                shell=True ),

        # Spawn Robot URDF
        #ExecuteProcess(
        #    cmd=["bash /home/jhsrobo/corews/src/core/launch/gazebo.bash"],
        #        shell=True ),

        # Uncomment to launch the Robot Visualizer GUI (RVIZ)

        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            output='screen',
            arguments=['-d', LaunchConfiguration('rvizconfig')],       
        ),

    ])