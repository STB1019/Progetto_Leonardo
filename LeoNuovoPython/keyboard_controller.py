"""
Function to analyze in which direction moving and for how long 

format of the messages: MMM

MMM : characters for movement
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
import os

def write_to_file(movement, key):
    message = f"{movement}"
    with open('key.txt', 'w') as file:
        file.write(message)

def display_commands():
    os.system('cls' if os.name == 'nt' else 'clear')
    print("Current controls:")
    print("w - Move forward")
    print("s - Move backward")
    print("a - Turn left")
    print("d - Turn right")
    print("r - Front axis up")
    print("f - Front axis down")
    print("t - Middle axis up")
    print("g - Middle axis down")
    print("y - Back axis up")
    print("h - Back axis down")
    print("u - Balance axis up")
    print("j - Balance axis down")
    print("q - Quit")
    print("\nCurrent movement:", end=" ")

def main():
    print("Press keys to control Leonardo. Press 'q' to quit.")
    current_movement = ""
    key_pressed = False
    last_key = None
    
    while True:
        display_commands()
        print(current_movement if current_movement else "None")
        
        if keyboard.is_pressed('w') and last_key != 'w':
            current_movement = "FWD"
            last_key = 'w'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('s') and last_key != 's':
            current_movement = "BCK"
            last_key = 's'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('a') and last_key != 'a':
            current_movement = "LFT"
            last_key = 'a'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('d') and last_key != 'd':
            current_movement = "RGH"
            last_key = 'd'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('r') and last_key != 'r':
            current_movement = "S1U"
            last_key = 'r'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('f') and last_key != 'f':
            current_movement = "S1D"
            last_key = 'f'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('t') and last_key != 't':
            current_movement = "S2U"
            last_key = 't'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('g') and last_key != 'g':
            current_movement = "S2D"
            last_key = 'g'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('y') and last_key != 'y':
            current_movement = "S3U"
            last_key = 'y'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('h') and last_key != 'h':
            current_movement = "S3D"
            last_key = 'h'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('u') and last_key != 'u':
            current_movement = "S4U"
            last_key = 'u'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('j') and last_key != 'j':
            current_movement = "S4D"
            last_key = 'j'
            write_to_file(current_movement, "")
        elif keyboard.is_pressed('q'):
            print("Quitting...")
            break
        else:
            if last_key is not None and not keyboard.is_pressed(last_key):
                current_movement = "None"
                write_to_file("O", "")
                last_key = None
        
        time.sleep(0.01)  # Small delay to prevent high CPU usage

if __name__ == "__main__":
    main()