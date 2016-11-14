# RoboMuse-4.0
The following repository contains the arduino and ROS files to operate the RoboMuse 4.0 robot from IIT Delhi. Please follow the following steps to run the robot.INSTRUCTIONS:

1. Before proceeding to operate the robot, ensure the all the connections on the robot are tight and in the right place.

2. Switch on the power supply for the robot and the kinect using the 2 switches which are present on the power board.

3. Connect the USB extender and the kinect to the USB ports on the laptop

4. Upload the Code 'teletele' onto the Arduino Mega which is attached to the base of the robot.

5. Upload the Code 'telenew/teleopbest' onto the Arduino Mega which is attached to the first rack of the robot.

6. Make a note of the Serial ports of both the Arduinos, which could be accessed through the 'tools' option present on the IDE.

7. Each of the following command is to be typed and executed in an individual terminal
	
	          a. roscore
	
 	          b. rosrun rosserial_python serial_node.py  <Enter Serial port of the 1st Arduino> eg. rosrun rosserial_python serial_node.py /dev/ttyACM0
	
	          c. rosrun rosserial_python serial_node.py <Enter Serial port of the 2nd Arduino>
	
	          d. roslaunch  robomuse robomuse_depth_reg.launch
	
	          e. roslaunch robomuse find_object_3d.launch
	  
	          f. roslaunch robomuse robomuse_rtab.launch
	
	          g. roslaunch robomuse robomuse_move_base.launch
	
	          h. roslaunch robomuse robomuse_nav2d_op.launch
	
	          i.  rosrun robomuse move_group_interface_tutorials

8. Upon doing so the robot begins to explore the workspace, and you can view the result of the exploration in Rviz and RTAB.





Warnings:#

    1. Please be ready to plug out the arduino in case of any mishap.

     2. The kinect can only detect obstacles which are at a distance of 30cm or more, so do not place anything extremely close to the robot initially.

     3. Charge the batteries regularly.

     4. In case rosserial fails to work, restart the robot.

      5. To check the accuracy of the encoder reading, open the Serial Monitor of the IDE belonging to code 'teletele'.

      6. In case the robot moves in an uncontrolled fashion (extremely high velocity), switch off the power supply and ensure the  connections from the encoder to the kangaroo are tight (Encoders are attached to the wheels, whereas the kangaroo is attached to the Sabertooth).

       7. Ensure the reading on the Power circuit of the kinect does not exceed 12.1V.

       8. Ensure the power circuit of the kinect receives 24V and the Motor driver of the robot receives nothing more than 12V.
 

