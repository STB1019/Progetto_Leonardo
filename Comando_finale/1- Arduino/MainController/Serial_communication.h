#include <Softwareserial.h>
 
void communicationSerial(){
    
    serial_movement.begin(1000);
    serial_sonar.begin(2000)


    wait(1);

    serial_movement.close();
    serial_sonar.close();

}
