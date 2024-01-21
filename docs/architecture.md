# Architecture
The following file outlines the structure of the ROVOTICS software stack. It covers the ROS Structure, as well as Topside, Bottomside, and Opside, and the camera system. It'll also outline the purpose of each package.

Topside refers to all of the software that runs on the TCU. Bottomside refers to all of the software that runs on the ROV. And Opside refers to all of the code that runs on the Ops Laptop. Each "side" is launched separately, and can run independently of the other "sides", with reduced functionality.

All computers in our system (TCU, ROV, Ops Laptop, Cameras) are connected to the same router, housed within the TCU. This facilitates easy communication between devices. ROS instances on one computer can easily connect to other ROS instances on different computers on the same network.

This file will cover what each package does, but it won't cover the specifics - refer to the individual packages for that. It will cover the macroscopic view of our software, above the package level.

The packages detailed in this file compose the CORE system, meaning they don't change much from year to year. The purpose of the CORE system is to provide a stable, competition agnostic way to operate the ROV. It's designed to be as modular as possible so that mission-specific software can easily be added on.

## Topside
Topside acts as the client. It's more powerful than Bottomside, so wherever possible, all of the heavy computing is done above water. Topside handles all of the "control" software. The TCU performs the following:
* Handles joystick input from the pilot.
* Controls the ROV thruster sensitivity.
* Calculates desired ROV Velocity.
* Detects, switches, and displays camera feeds.
* Records camera feed and broadcasts to Opside.
* Has the ability to control grippers.

The following packages are included on Topside:
* core
* gripper_control
* motion_control
* pilot_gui

## Bottomside
Bottomside acts as the server. It does essentially nothing that Topside doesn't tell it to do. Bottomside refers to all of the "interface" software, running on the ROV. It does the following:
* Spins the thrusters.
* Controls our tools via GPIO.
* Monitors our sensors and broadcasts to Topside.

The following packages are included on Bottomside:
* core
* gpio_interface
* sensor_interface
* thruster_interface

## Opside
Opside is different every year. In 2021, Opside was a glorified calculator. In 2022, Opside was an image processor outside of ROS. In 2023, Opside was ROS-integrated and performed heavy computational tasks like photogrammetry.
Opside runs on the "Ops Laptop", which has a high-performance CPU and GPU. Anthing particularly hardware intensive is offloaded onto this side, making Opside a good example of how software tools are easily added on to the CORE system.

## Cameras
The cameras exist outside of the ROS ecosystem. Instead, they stream their video to their own IP address, while pinging Topside. The rest of the camera feed process is handled by the pilot_gui package. When Topside detects one of these pings, it checks the IP address of the ping for a camera feed, and captures it, displaying it to the pilot. You can read more about the pilot_gui package and its functionality in the package outlines.

## Package Outlines

#### core
A package in common between Topside and Bottomside. This contains our in-house library, as well as our custom messages, services, and launch files. It also contains all of our documentation for the CORE system, and scripts for setting up and updating said system.
#### gripper_control
Controls both solenoids for gripper pneumatics in the TCU with one button. Pressing the trigger opens or closes the gripper that is currently in view of the active camera.
#### motion_control
Takes the pilot's input from the joysticks and converts it into the desired ROV velocity, in the form of a vector. Also manages the pilot's desired sensitivity.
#### pilot_gui
Listens for pings from cameras, and then captures their video feeds. Listens to button input from the pilot to cycle through cameras. Cameras can be remapped on the fly to different button inputs. The pilot_gui also has the ability to add new cameras mid-operation.
The camera feed is also overlayed with important information, like the thruster status and the current ROV sensitivity.
#### gpio_interface
Toggles the status of several relays on the ROV HAT. These are typically connected to mission-specific tools.
#### sensor_interface
Reads data from an array of sensors, including an IMU, depth sensor, internal temperature and humidity probe, external temperature probe, and a leak detector. Publishes the data so that any other ROS program can view it.
#### thruster_interface
Converts the velocity vector from motion_control into a set of effort values for the thrusters, and spins them.