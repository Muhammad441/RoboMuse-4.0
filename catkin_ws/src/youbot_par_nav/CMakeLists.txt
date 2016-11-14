cmake_minimum_required(VERSION 2.8.3)
project(youbot_par_nav)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED
             COMPONENTS
             moveit_core
             moveit_ros_planning
             moveit_ros_planning_interface
             pluginlib
             cmake_modules
             geometric_shapes
             tf
)

find_package(Boost REQUIRED system filesystem date_time thread)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pr2_moveit_tutorials
  CATKIN_DEPENDS 
    moveit_core
    moveit_ros_planning_interface
    interactive_markers
)
find_package(Eigen REQUIRED)

###########
## Build ##
###########


include_directories(SYSTEM ${Boost_INCLUDE_DIR} ${EIGEN_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

add_executable(move_group_interface_tutorial src/move_group_interface_tutorial.cpp)
target_link_libraries(move_group_interface_tutorial ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS move_group_interface_tutorial DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(newmove_group src/newmove_group.cpp)
target_link_libraries(newmove_group ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS newmove_group DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(send_goal src/send_goal.cpp)
target_link_libraries(send_goal ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS send_goal DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(PROGRAMS
  scripts/move_group_python_interface_tutorial.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


