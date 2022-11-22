#include<HardwareSerial.h>
#include<string.h>
#define RX 16
String Reading;
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600,SERIAL_8N1, RX,NULL);
  
}

void loop() {
  acStr();
  delay(1000);
}
void acStr()
{
  
  
  // String table1="24870484856485469705549543",table2="24870484856485065525269493",kitchen="24870484856485169545668573",Reading;
    if(Serial2.available())
  {
      Reading="";
      int i=0;
      while(Serial2.available())
          {
              char data =Serial2.read();
              int datainDEC = data;
              if(data!='\n' && Reading.length()<26 && i<26)
                {
                Reading=Reading + datainDEC;
                }
                
              else{
                exit;
              }
              i++;
            
          }
          int a = Reading.length();
      Serial.println(Reading);
      Serial2.flush();
      Serial.println();
  }
  
}