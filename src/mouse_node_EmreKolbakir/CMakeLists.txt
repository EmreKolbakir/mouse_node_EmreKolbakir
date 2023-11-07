cmake_minimum_required(VERSION 2.8.3)
project(mouse_node_EmreKolbakir)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  # ...
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(mouse_publisher src/mouse_publisher.cpp)
add_executable(mouse_subscriber src/mouse_subscriber.cpp)
target_link_libraries(mouse_subscriber ${catkin_LIBRARIES})
target_link_libraries(mouse_publisher ${catkin_LIBRARIES})
