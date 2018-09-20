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

#include <chrono>
#include <memory>
#include "class_loader/class_loader_register_macro.h"
#include "rclcpp/rclcpp.hpp"
#include "micrortps_demo_msgs/msg/hello_world.hpp"
#include "publisher/publisher_component.hpp"

using namespace std::chrono_literals;

namespace micrortps_helloworld_demo
{

/* Create a Publisher component. */
PublisherNode::PublisherNode()
: Node("publisher_node"), count_(0)
{
  publisher_ = create_publisher<micrortps_demo_msgs::msg::HelloWorld>("HelloWorldTopic");

  /* Create a timer to schedule periodic message publishing. */
  timer_ = create_wall_timer(1s, std::bind(&PublisherNode::on_timer, this));
}

void PublisherNode::on_timer()
{
  auto msg = std::make_shared<micrortps_demo_msgs::msg::HelloWorld>();
  msg->index = ++count_;
  msg->message = "Hello, world!";
  RCLCPP_INFO(this->get_logger(), "Sending: '%s' : %d", msg->message.c_str(), msg->index);
  publisher_->publish(msg);
}

} // namespace micrortps_helloworld_demo

/* Register the component with class_loader. */
CLASS_LOADER_REGISTER_CLASS(micrortps_helloworld_demo::PublisherNode, rclcpp::Node)
