# Import SerialWriter from serial_write_module
from serial_write_module import SerialWriter as sw
from Talker import Talker
from playsound import playsound
import time

def read_api_key():
    try:
        with open('api.ttt', 'r') as file:
            return file.readline().strip()
    except FileNotFoundError:
        print("Error: api.ttt file not found")
        return None
    except Exception as e:
        print(f"Error reading api.ttt: {e}")
        return None

api_key = read_api_key()

ja = Talker("ja", "", False)

it = Talker("jXaluZuLEjmMer7FT0Q2", api_key, False)

el = Talker("MhCxqsUNqPcgb5bNYy5r", api_key, False)


def initialize():
    def select_module():
        # Display module selection menu
        print("Select a module:")
        print("1. MQTT")
        print("2. GUI")
        print("3. KEY")
        module_choice = input("Enter your choice (1,2,3): ")

        # Use match-case to handle module selection
        
        if module_choice=="1":
            it.talk("Modulo Mqtt in Attivazione")
            # Import MQTT module
            from mqtt_read_module import Module as Mod
            return Mod
        if module_choice=="2":
            it.talk("Modulo Gui in Attivazione")
            # Import GUI module
            from gui_read_module import Module as Mod
            return Mod
        if module_choice=="3":
            it.talk("Modulo Tastiera in Attivazione")
            # Import KEY module
            from keyboard_read_module import Module as Mod
            return Mod

    return select_module()

if __name__ == "__main__":

    playsound("jet2.mp3", block=False)

    """ja.talk("Initializing Robot Systems...")

    ja.talk("Diagnostic Report: Leonardo 3.0")

    ja.talk("Power Core Status: Online and stable.") 

    ja.talk("Fusion reactor at 98% efficiency.")

    ja.talk("Motors: All motors are operational.")
    ja.talk("Linear Axis: Green across the board.")
    ja.talk("Gyrosensors: Calibrated and responsive.")

    ja.talk("ALL SYSTEM NOMINAL")

    ja.talk("Starting Voice interface")

    ja.talk("Ready")
    
    el.talk("Initializing Robot Systems...")

    el.talk("Diagnostic Report: Leonardo 3.0")

    el.talk("Power Core Status: Online and stable.") 

    el.talk("Fusion reactor at 98% efficiency.")

    el.talk("Motors: All motors are operational.")
    el.talk("Linear Axis: Green across the board.")
    el.talk("Gyrosensors: Calibrated and responsive.")

    el.talk("ALL SYSTEM NOMINAL")

    el.talk("Starting Italian Voice interface")

    el.talk("Ready")"""

    it.talk("Leonardo Operativo, in attesa di istruzioni")

    
    # Initialize the selected module
    module = initialize()
    # Create an instance of SerialWriter
    #serial_bridge = sw()
    it.talk("Modulo Attivo")
    it.talk("Inizio comunicazione seriale")
    if module:
        # Create an instance of the selected module
        module_instance = module()
        print(module_instance.name)
        while True:
            # Read data from the module
            ret = module_instance.read()
            if(ret != None):
                print(ret)
                # Send the received data through the serial bridge
                s_w=sw()
                s_w.send_string(ret)
            time.sleep(0.01)
                
        
    else:
        print("Failed to initialize module")
