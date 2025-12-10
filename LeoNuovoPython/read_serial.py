import serial
import time
import serial_write_module as u_writer

# Configure the serial port
ser = serial.Serial(
    port='/dev/ttyUSB0',           # Serial port name
    baudrate=115200,         # Baud rate
    timeout=0.01              # Read timeout in seconds
)

try:
    while True:
        # Read data from serial port
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            print(f"Received: {line}")
            if line[0] == 'D':
 #                 print(f'aaa')
                  str = line[2:]
                  distance = str.split(";")
                  temp = int(distance[1])
                  print(distance)
                  if temp<50:
                      ser.write(b'O')
                  elif (temp<100 & temp>=50):
                      ser.write(b'P100')
                  else:
                      ser.write(b'F')
                

            
        
        #time.sleep(0.1)  # Small delay to prevent CPU overuse

except KeyboardInterrupt:
    print("\nStopping serial read...")
    ser.close()
except serial.SerialException as e:
    print(f"Serial port error: {e}")
    ser.close()
finally:
    if ser.is_open:
        ser.close()


