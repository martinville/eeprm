/*
  eeprm.cpp - Library for writing complete strings to flash memory in segments.
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
#include <WString.h>
#include <EEPROM.h>
#include "Arduino.h"
#include "eeprm.h"

Eeprm::Eeprm(int Nothing ){}
void Eeprm::writedata(int field,String datatowrite )
{
  int i;
  String CurCharacter;
  char CharConv;
  int CurASCIICode;  
  field = (field-1)*20;

  datatowrite=datatowrite+"~~~~~~~~~~~~~~~~~~~~";  
   for (i=0; i <= 19; i++)
   {
      CurCharacter = datatowrite.substring(i,i+1); //Get String character
      CharConv = CurCharacter.charAt(0); //Convert string to Char      
      CurASCIICode=CharConv; //Convert char to integer (ASCII CODE)
      EEPROM.write(i+field, CurASCIICode);   
   }  
}
String Eeprm::readdata(int field)
{
  String dataToRead  ="";
  int val;
  field = (field-1)*20;
  int i; 
   for (i=field; i <= field+19; i++)
   {    
    val=EEPROM.read(i);
	if(val==126){break;}
    dataToRead   += char(val);
   } 	
return dataToRead  ;
}
