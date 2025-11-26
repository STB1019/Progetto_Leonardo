# Import required libraries
import os
import time
import paho.mqtt.client as mqtt

class Module:
    def __init__(self):
        # Initialize the MQTT module
        self.name = "MQTT"
        self.mqtt_message = None
        
        # Set up MQTT client
        self.client = mqtt.Client()
        self.client.on_message = self.on_message
        
        # Connect to the MQTT broker
        self.client.connect("broker.hivemq.com", 1883)
        
        # Subscribe to the specified topic
        self.client.subscribe("leonardo/topic")
        
        # Start the MQTT client loop
        self.client.loop_start()

    def on_message(self, client, userdata, message):
        # Callback function to handle incoming MQTT messages
        self.mqtt_message = message.payload.decode()

    def read(self):
        # Wait for a message to be received
        while self.mqtt_message is None:
            time.sleep(0.01)  # Check every 10 milliseconds
        
        # Store the received message and reset the mqtt_message attribute
        message = self.mqtt_message
        self.mqtt_message = None
        
        # Return the received message
        return message