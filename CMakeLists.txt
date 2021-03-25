cmake_minimum_required(VERSION 3.0.2)
project(dynamic_reconfigure_group_issue)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  dynamic_reconfigure
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################
generate_dynamic_reconfigure_options(cfg/Example.cfg)

###################################
## catkin specific configuration ##
###################################
catkin_package()

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(dynamic_reconfigure_server src/main.cpp)
target_link_libraries(dynamic_reconfigure_server ${catkin_LIBRARIES})
add_dependencies(dynamic_reconfigure_server ${PROJECT_NAME}_gencfg)