#!/usr/bin/env python
import rospy
import baxter_interface

from std_msgs.msg import String


class Helper(object):

    def callback(data):
        rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

    def __init__(self):

        self._lgrip = baxter_interface.Gripper("left")
        self._rgrip = baxter_interface.Gripper("right")

#        DEFINE THE VARIABKE FROM THE MESSAGE
        self._command = data.data
        self._rgrip.calibrate()

def check(self):
    b=0;
    while b==0:
         rospy.sleep(0.1)
         if self._command == "Positive":
                self._rgrip.close()
         elif self._command == "Negative":
                self._rgrip.open()





def main():
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("chatter", String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

    rospy.init_node("gripper")
    h = Helper()
    while not rospy.is_shutdown():
        h.check()

if __name__ == "__main__":
    main()
