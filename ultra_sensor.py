"""
This Raspberry Pi code was developed by newbiely.com
This Raspberry Pi code is made available for public use without any restriction
For comprehensive instructions and wiring diagrams, please visit:
https://newbiely.com/tutorials/raspberry-pi/raspberry-pi-ultrasonic-sensor
"""


import RPi.GPIO as GPIO
import time
import serial

# Set the GPIO mode (BCM or BOARD)
GPIO.setmode(GPIO.BCM)

# Define GPIO pins for the ultrasonic sensor
TRIG_PIN = 23
ECHO_PIN = 24

# Set the trigger and echo pins
GPIO.setup(TRIG_PIN, GPIO.OUT)
GPIO.setup(ECHO_PIN, GPIO.IN)
ser = serial.Serial('/dev/ttyUSB0',115200, timeout=1)

def get_distance():
    # Send a short pulse to the trigger pin
    GPIO.output(TRIG_PIN, GPIO.HIGH)
    time.sleep(0.00001)
    GPIO.output(TRIG_PIN, GPIO.LOW)

    # Measure the duration for the echo pulse
    while GPIO.input(ECHO_PIN) == 0:
        pulse_start = time.time()

    while GPIO.input(ECHO_PIN) == 1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start

    # Calculate the distance based on the speed of sound (34300 cm/s)
    distance = pulse_duration * 34300 / 2

    return distance

try:
    while True:
        distance = get_distance()
        if distance <10:
            ser.write(b"O\n")
            print("O")
        if distance > 50:
            ser.write(b"F\n")
            print("F")

        line = ser.readline().decode('utf-8').rstrip()
        
        print(distance)
        time.sleep(0.1)

except KeyboardInterrupt:
    # If the user presses Ctrl+C, clean up the GPIO configuration
    ser.write(b"O\n")
    GPIO.cleanup()