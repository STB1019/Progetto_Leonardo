import serial
import time

# Configure the serial port
ser = serial.Serial(
    port='/dev/ttyUSB2',           # Serial port name
    baudrate=9600,         # Baud rate
    timeout=10              # Read timeout in seconds
)

try:
    while True:
        # Read data from serial port
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            print(f"Received: {line}")
        
        time.sleep(0.1)  # Small delay to prevent CPU overuse

except KeyboardInterrupt:
    print("\nStopping serial read...")
    ser.close()
except serial.SerialException as e:
    print(f"Serial port error: {e}")
    ser.close()
finally:
    if ser.is_open:
        ser.close()
