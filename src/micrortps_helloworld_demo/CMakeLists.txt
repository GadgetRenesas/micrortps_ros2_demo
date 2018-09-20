cmake_minimum_required(VERSION 3.5)
project(micrortps_helloworld_demo)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(class_loader REQUIRED)
find_package(micrortps_demo_msgs REQUIRED)

include_directories(include)

add_library(publisher_component SHARED src/publisher_component.cpp)
target_compile_definitions(publisher_component PRIVATE "MICRORTPS_HELLOWORLD_DEMO_BUILDING_DLL")
ament_target_dependencies(publisher_component rclcpp class_loader micrortps_demo_msgs)

add_library(subscriber_component SHARED src/subscriber_component.cpp)
target_compile_definitions(subscriber_component PRIVATE "MICRORTPS_HELLOWORLD_DEMO_BUILDING_DLL")
ament_target_dependencies(subscriber_component rclcpp class_loader micrortps_demo_msgs)

rclcpp_register_node_plugins(publisher_component "PublisherNode")
rclcpp_register_node_plugins(subscriber_component "SubscriberNode")

add_executable(publisher src/standalone_publisher.cpp)
add_executable(subscriber src/standalone_subscriber.cpp)

target_link_libraries(publisher publisher_component)
ament_target_dependencies(publisher rclcpp micrortps_demo_msgs)

target_link_libraries(subscriber subscriber_component)
ament_target_dependencies(subscriber rclcpp micrortps_demo_msgs)

ament_export_dependencies(ament_cmake)
ament_export_dependencies(rclcpp)
ament_export_dependencies(class_loader)
ament_export_dependencies(micrortps_demo_msgs)

ament_export_include_directories(include)

ament_export_libraries(publisehr_component)
ament_export_libraries(subscriber_component)

install(DIRECTORY
  include/publisher
  include/subscriber
  DESTINATION include
  )

install(TARGETS
  publisher_component
  subscriber_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  )

install(TARGETS
  publisher
  subscriber
  DESTINATION lib/${PROJECT_NAME}
  )

ament_package()
