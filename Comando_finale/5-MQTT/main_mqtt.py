#Thomas

import random
import time

from paho.mqtt import client as mqtt_client

class MqttClass:

    def __init__(self, broker, port, topic, id):

        self.broker = broker
        self.port = port
        self.topic = topic
        # generate client ID with pub prefix randomly
        self.client_id = f'python-mqtt-{random.randint(0, 1000)}'
        self.client = self.connect_mqtt()
        self.lastmsg = ""
        self.id = id

    def connect_mqtt(self):
        def on_connect(client, userdata, flags, rc):
            if rc == 0:
                print(f"Connected to MQTT Broker! -> {self.id}")
            else:
                print("Failed to connect, return code %d\n", rc)

        client = mqtt_client.Client(self.client_id)
        # client.username_pw_set(username, password)
        client.on_connect = on_connect
        client.connect(self.broker, self.port)
        return client

    def publish(self, msg):
        result = self.client.publish(self.topic, msg)
        # result: [0, 1]
        status = result[0]
        if status == 0:
            print(f"Send `{msg}` to topic `{self.topic}`")
        else:
            print(f"Failed to send message to topic {self.topic}")
        msg_count = 0 + 1

    def subscribe(self):
        client = self.client
        def on_message(client, userdata, msg):
            #print(str(msg.payload.decode()))
            self.lastmsg = str(msg.payload.decode())

        client.subscribe(self.topic)
        client.on_message = on_message
        client.loop_forever()

    def getLastMsg(self):
        try:
            return self.lastmsg
        except Exception:
            return ""

