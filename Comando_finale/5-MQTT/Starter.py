#!/usr/bin/env python

import os
import math
import time as t
from main_mqtt import MqttClass as mqtt
#from RPi import GPIO                   use this if you want to use GPIOs from the raspberry            
import random

#import multiprocessing as th
import threading as th




#setup  MQTT connection

l = mqtt("broker.hivemq.com",1883,"/unibs/IEEESTB01019/Projects/Leonardo",0)

#running mqtt connection in a separate thread
t.sleep(0.2)
x = th.Thread(target = l.subscribe)
x.start()

def jsonDecompose(j):
    j = f"{j} "
    j1 = []
    if j[0] != "{":
        return [-1,-1,-1,-1]
    j = j.replace(",", ":")
    j = j.replace("[", ":")
    j = j.replace("]", ":")

    j1 = j.split(":")

    return [j1[1], j1[3], j1[6], j1[7]] #TODO: when sending the json check if the field returned by this function are the correct ones


while True:
    
    j = l.getLastMsg()
    js = jsonDecompose(j)
    print(f" Topic {str(int(random.random*100))} -> {js}")

    l.publish("ERROR 404: LEONARDO NOT FOUND")
    #l.publish("{ \"ts\":" + str(t.time()) + ", \"distance\":" + "ERROR" + ", \"location\": [" ERROR "]}")          proto of the message to be sent

    t.sleep(0.5)

    print("ERROR 404: LEONARDO NOT FOUND")

   

