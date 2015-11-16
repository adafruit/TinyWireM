#include <TinyWireM.h>
//Demo of reading AT24 EEPROM, and logging the results to serial. Reads the first 256 bytes. 
//#define DoWrite //uncomment to write consecutive integers to first 256 bytes while sketch runs
//comment out Serial statements for boards without hardware serial. 


byte i=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //comment out if you're using a chip w/out serial.
  TinyWireM.begin();                    // initialize I2C lib
  Serial.println("Tinywire begun"); //comment out if you're using a chip w/out serial.
}

void loop() {
  // put your main code here, to run repeatedly:

#ifdef DoWrite
  TinyWireM.beginTransmission(0x50);
  TinyWireM.send(0x00);
  TinyWireM.send(i);
  TinyWireM.send(i);
  TinyWireM.endTransmission();          // Send to the slave
  delay(500);
#endif
  TinyWireM.beginTransmission(0x50);
  TinyWireM.send(0x00);
  TinyWireM.send(i);
  TinyWireM.endTransmission();  
  TinyWireM.requestFrom(0x50,1);
  Serial.println(TinyWireM.receive()); //comment out if you're using a chip w/out serial.
  delay(500);
  i++;
}
