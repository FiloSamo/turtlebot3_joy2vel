# Turtlebot3 control using Joystick

This package has been developed for ros2 Humble.
If the package joy is installed with the ros2 installation, then it is possible to use it with this package to control the turtlebot3 instad to use the teleop_key node.

The package named Joy recognizes the joystick and the joystic information are published inside the topic /joy with the datatype sensor_msgs::msg::Joy.
The turtlebot3_joy2vel package converts the data published on the /joy topic into geometry_msgs::msg::Twist and 
it publishes it in the /cmd_vel topic used by the turtlebot3 to set the linear and angular velocity.

# Installation
Create a new package folder named turtlebot3_joy2vel and in the terminal type this command:

'''
git clone ...
'''

Then move to the workspace folder and compile the package using:

'''
colcon build
'''
