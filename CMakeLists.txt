cmake_minimum_required(VERSION 3.0.2)
project(nrs_admittance_control_pkg)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(nrs_admittance_control
  src/nrs_admittance.cpp
)

add_executable(admittance_node src/admittance_node.cpp)
target_link_libraries(admittance_node
  nrs_admittance_control
  ${catkin_LIBRARIES}
)
