cmake_minimum_required(VERSION 3.0.2)
project(comms)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs message_generation)

## Declare ROS messages and services
add_message_files(FILES LaserScan.msg)
add_service_files(FILES laser_scan.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)


## Declare a catkin package
catkin_package(CATKIN_DEPENDS message_runtime)


## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(laser_scan_publisher src/laser_scan_.cpp)
target_link_libraries(laser_scan_publisher ${catkin_LIBRARIES})
add_dependencies(laser_scan_publisher )

add_executable(point_cloud_publisher src/point_cloud_.cpp)
target_link_libraries(point_cloud_publisher ${catkin_LIBRARIES})
add_dependencies(point_cloud_publisher )