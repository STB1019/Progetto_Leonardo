"""
Function to analyze in which direction moving and for how long 

format of the messages: MMMDDDDK

MMM : characters for movement
DDDD : timer 0 - 9999 for movement
K : key character for message

    ###   DC DIRECTION    ###

FWD  ->  Leonardo moving forward (keyboard 'w')
BCK  ->  Leonardo moving backwards (keyboard 's')
LFT  ->  Leonardo turning  left (keyboard 'a')
RGH  ->  Leonardo turning right (keyboard 'd')

    ###   STEPPER DIRECTION   ###


S1U  ->  moving front axis up (keyboard 'r')
S1D ->  moving front axis down (keyboard 'f')
S2U  ->  moving middle axis up (keyboard 't')
S2D  ->  moving middle axis down (keyboard 'g')
S3U  ->  moving back axis up (keyboard 'y')
S3D  ->  moving back axis down (keyboard 'h')
S4U  ->  moving balance axis up (keyboard 'u')
S4D  ->  moving balance axis down (keyboard 'j')
"""

import keyboard
import time

def write_to_file(message):
    with open('key.txt', 'w') as file:
        file.write(message)

def main():
    print("Type your message and press Enter to send. Press 'q' to quit.")
    
    while True:
        message = input("Enter message (format: MMMDDDDK): ")
        if message.lower() == 'q':
            print("Quitting...")
            break
        else:
            write_to_file(message)
            
main()
