/*
  Eeprm Example - Library for writing complete strings to flash memory in segments.
  Created by Martin Viljoen 2018/01/14.

  
  [WARNING]
  The EEPROM's memory is rated for more or less 100 000 write cycles. Do not write to memory in a loop.
  It's recommended to only use this library to store settings for when you want to reload parameters after
  the microcontroller powered down.
  
  [USAGE]
  Field lengths are limited to 20 ASCII characters in 20 fields.
  ~ is an illigal character and may not be used.
  Eeprm Eeprm(0); Must be called before reading or writing.
  
    
  [Writing to memory]
  Eeprm Eeprm(0);
  Eeprm.writedata(Field_Number,"Text_String_1");
  Eeprm.writedata(Field_Number,"Text_String_2");
  
  [Reading from memory]
  Eeprm Eeprm(0);
  Dataread=Eeprm.readdata(Field_Number);
  Dataread=Eeprm.readdata(Field_Number);
  
*/
#include  <EEPROM.h>
#include <eeprm.h>

String Dataread;

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(512); 
  //Write to memory
  Eeprm Eeprm(0);
  Eeprm.writedata(1,"Martin");
  Eeprm.writedata(2,"Viljoen");
  
}

void loop()
{
  //Read from field 1 in memory
  Eeprm Eeprm(0);
  Dataread=Eeprm.readdata(1);
  Serial.println(Dataread);
  //Read from field 2 in memory
  Dataread=Eeprm.readdata(2);
  Serial.println(Dataread);
}
