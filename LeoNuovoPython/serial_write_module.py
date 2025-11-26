import serial

class SerialWriter:
    def __init__(self, port='/dev/ttyUSB2', baudrate=9600, timeout=10):
        # Initialize the serial connection with specified parameters
        self.ser = serial.Serial(port, baudrate, timeout=timeout)
        pass

    def send_string(self, message):
        # Convert the message to ASCII and send it over the serial connection
        ascii_message = message.encode('ascii')
        self.ser.write(ascii_message)

    def close(self):
        # Close the serial connection
        self.ser.close()
