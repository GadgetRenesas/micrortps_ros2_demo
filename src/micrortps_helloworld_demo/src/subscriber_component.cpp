// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "class_loader/class_loader_register_macro.h"
#include "rclcpp/rclcpp.hpp"
#include "micrortps_demo_msgs/msg/hello_world.hpp"
#include "subscriber/subscriber_component.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace micrortps_helloworld_demo
{

/* Create a Subscriber component. */
SubscriberNode::SubscriberNode()
: Node("subscriber_node")
{
  subscription_ = this->create_subscription<micrortps_demo_msgs::msg::HelloWorld>(
    "HelloWorldTopic",
    std::bind(&SubscriberNode::display_helloworld, this, _1));
}

void SubscriberNode::display_helloworld(const micrortps_demo_msgs::msg::HelloWorld::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logger(), "Receiving: '%s': %d", msg->message.c_str(), msg->index);
}

} // namespace micrortps_helloworld_demo

/* Register the component with class_loader. */
CLASS_LOADER_REGISTER_CLASS(micrortps_helloworld_demo::SubscriberNode, rclcpp::Node)
