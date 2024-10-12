
/*
 * Author: Filippo Samorì
 * Email: filippo.samori@studio.unibo.it
 * Date: 12/10/2024
 * Description: This package converts sensor_msgs::msg::Joy messages to geometry_msgs::msg::Twist, 
 * specifically implemented for controlling TurtleBot3 with a joystick via the 'Joy' ROS2 package
 * License: MIT License
 */

#include "Publisher.cpp"

const float max_lin_speed = 0.5;
const float max_ang_speed = 0.8;

int main(int argc, char * argv[]){
rclcpp::init(argc, argv);
rclcpp::spin(std::make_shared<Publisher>());
rclcpp::shutdown();
return 0;
}

/*
Copyright (c) 2024 Filippo Samorì

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to deal 
in the Software without restriction, including without limitation the rights to use, 
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies 
or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/