cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(pcl_tutorials)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# basics
add_executable(pilot src/basics/pilot.cpp)
target_link_libraries(pilot ${PCL_LIBRARIES})

# pcl_visualizer
add_executable(view src/pcl_visualizer/view.cpp)
target_link_libraries(view ${PCL_LIBRARIES})
