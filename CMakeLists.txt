cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(pcl_tutorials)

find_package(PCL 1.11.0 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# basics
add_executable(pcl_version src/basics/pcl_version.cpp)
target_link_libraries(pcl_version ${PCL_LIBRARIES})

# pcl_visualizer
add_executable(pcl_visualizer_basic src/pcl_visualizer/pcl_visualizer_basic.cpp)
target_link_libraries(pcl_visualizer_basic ${PCL_LIBRARIES})

add_executable(pcl_viewer_elipse src/pcl_visualizer/pcl_viewer_elipse.cpp)
target_link_libraries(pcl_viewer_elipse ${PCL_LIBRARIES})