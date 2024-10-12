
/*
 * Author: Filippo Samorì
 * Email: filippo.samori@studio.unibo.it
 * Date: 12/10/2024
 * Description: This package converts sensor_msgs::msg::Joy messages to geometry_msgs::msg::Twist, 
 * specifically implemented for controlling TurtleBot3 with a joystick via the 'Joy' ROS2 package
 * License: MIT License
 */

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/joy.hpp"


using namespace std::chrono_literals;

extern const float max_lin_speed;
extern const float max_ang_speed;

class Publisher:public rclcpp::Node
{
private:
    /* data */
    void topic_callback(const sensor_msgs::msg::Joy::SharedPtr msg) const{

        geometry_msgs::msg::Twist message_vel;
        // manipulate data
        //
        message_vel.linear.x = msg->axes[1]*max_lin_speed;
        message_vel.linear.y = 0;
        message_vel.linear.z = 0;

        message_vel.angular.x = 0;
        message_vel.angular.y = 0;
        message_vel.angular.z = msg->axes[2]*max_ang_speed; 

        RCLCPP_INFO(this->get_logger(), "Sended data: linear: [%f, %f, %f], angular: [%f, %f, %f]", 
        message_vel.linear.x, message_vel.linear.y, message_vel.linear.z, 
        message_vel.angular.x, message_vel.angular.y, message_vel.angular.z);

        // send the data to /cmd_vel
        publisher_->publish(message_vel);

    }
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

public:
    Publisher(/* args */) : Node("vel_cmd"){
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>("/joy", 10, std::bind(&Publisher::topic_callback, this, std::placeholders::_1));
    }

    ~Publisher(){}
};

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