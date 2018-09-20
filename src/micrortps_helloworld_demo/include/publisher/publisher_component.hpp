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

#if !defined MICRORTPS_HELLOWORLD_DEMO__PUBLISHER_COMPONENT_HPP_
#define MICRORTPS_HELLOWORLD_DEMO__PUBLISHER_COMPONENT_HPP_

#include "visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "micrortps_demo_msgs/msg/hello_world.hpp"

namespace micrortps_helloworld_demo
{

class PublisherNode : public rclcpp::Node
{
public:
  MICRORTPS_HELLOWORLD_DEMO_PUBLIC PublisherNode();

private:
  void on_timer();
  size_t count_;
  rclcpp::Publisher<micrortps_demo_msgs::msg::HelloWorld>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

} // namespace micrortps_helloworld_demo

#endif  // MICRORTPS_HELLOWORLD_DEMO__PUBLISHER_COMPONENT_HPP_
