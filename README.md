# Turtlebot3 control using Joystick

This package has been developed for ros2 Humble.
If the package **joy** is installed with the ros2 installation, then it is possible to use it with this package to control the turtlebot3 instad to use the teleop_key node.

The package named **joy** recognizes the joystick and the inputs from the device are published inside the topic /joy with the datatype **sensor_msgs::msg::Joy**.
The **turtlebot3_joy2vel** package converts the data published on the /joy topic into **geometry_msgs::msg::Twist** and 
it publishes it in the /cmd_vel topic used by the turtlebot3 to set the linear and angular velocity.

# Installation
Move to the src folder in the workspace, then clone the github directory:

```
cd ~/<workspace_name>/src
git clone ...
```

Then move to the workspace folder and compile the package using:

```
cd ~/<workspace_name>
rosdep install -i --from-path src --rosdistro humble -y
colcon build
```
# How to use

First of all run the . install/local_setup.bash file inside the package folder.

```
source ~/<workspace_name>/install/local_setup.bash
```


Then run the Joy package and the turtlebot3_joy2vel package:

```
ros2 run joy game_controller_node 
ros2 run turtlebot3_joy2vel translator
```
