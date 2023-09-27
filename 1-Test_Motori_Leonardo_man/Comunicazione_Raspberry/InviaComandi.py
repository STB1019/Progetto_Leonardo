#!/usr/bin/env python3

import rospy
import serial
from geometry_msgs.msg import Twist

def send_message(msg):
   x = round(msg.linear.x,1)
   z = round(msg.angular.z,1)

   if(x > 0 and z == 0):
        ser.write(("F"+str(abs(x))+"\n").encode('utf-8'))
        print("F"+str(abs(x))+"\n")

   elif(x < 0 and z == 0):
       ser.write(("B"+str(abs(x))+"\n").encode('utf-8'))
       print("B"+str(abs(x))+"\n")

   elif(z < 0 and x == 0):
       ser.write(("R"+str(abs(z))+"\n").encode('utf-8'))
	   print("R"+str(abs(z))+"\n")

   elif(z > 0 and x == 0):
       ser.write(("L"+str(abs(z))+"\n").encode('utf-8'))
 	   print("L"+str(abs(z))+"\n")



def callback(msg):
   send_message(msg)


rospy.init_node("sub_to_teleop_twist_keyboard")
sub = rospy.Subscriber('cmd_vel',Twist,callback)
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
rospy.spin()