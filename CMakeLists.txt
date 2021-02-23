cmake_minimum_required(VERSION 3.0.2)
project(comms)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs message_generation
geometry_msgs tf)

## Declare ROS messages and services
add_message_files(FILES LaserScan.msg)
add_service_files(FILES GetMap.srv)

#add_message_files(FILES PointCloud.msg)
## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs sensor_msgs)


## Declare a catkin package
catkin_package(
	#include_directories include
	CATKIN_DEPENDS message_runtime)


## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(laser_scan_file src/laser_scan_file.cpp)
target_link_libraries(laser_scan_file ${catkin_LIBRARIES})
#add_dependencies(laser_scan_publisher <INSERT HEADER FILE>)

add_executable(point_cloud_file src/point_cloud_file.cpp)
target_link_libraries(point_cloud_file ${catkin_LIBRARIES})
#add_dependencies(point_cloud_publisher comms_generate_msgs_cpp)

add_executable(laser_scan_listener src/laser_scan_listener.cpp)
target_link_libraries(laser_scan_listener ${catkin_LIBRARIES})

add_executable(odom_data src/odom_data.cpp)
target_link_libraries(odom_data ${catkin_LIBRARIES})

add_executable(transform_frame src/transform_frame.cpp)
target_link_libraries(transform_frame ${catkin_LIBRARIES})

add_executable(transform_frame_listener src/transform_frame_listener.cpp)
target_link_libraries(transform_frame_listener ${catkin_LIBRARIES})