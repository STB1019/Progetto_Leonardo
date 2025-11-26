
import paho.mqtt.client as mqtt
import time

# MQTT broker settings
broker_address = "broker.hivemq.com"
broker_port = 1883
topic = "leonardo/topic"

# Create MQTT client
client = mqtt.Client()

# Connect to the broker
client.connect(broker_address, broker_port)

# Message to send
message = "Hello, MQTT!"

try:
    while True:
        # Publish the message
        client.publish(topic, message)
        print(f"Sent message: {message}")
        
        # Wait for 5 seconds before sending the next message
        time.sleep(5)

except KeyboardInterrupt:
    print("Stopping the program...")

finally:
    # Disconnect from the broker
    client.disconnect()
    print("Disconnected from MQTT broker")
