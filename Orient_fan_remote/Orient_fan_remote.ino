/*
 *this code can be easily modified to operate different device by simply changing the HEX code.
*/




#include <IRremote.h>              //        we will set the state of of the pins (12,11,9,8,7,6) to HIGH initially 
IRsend irsend;                      //          and when we these pins gets connected to ground the associated 
int f, l, s1, s2, s3, s4;           //                 fxn will be called and the task will be performed

void fan()
{
  Serial.println("fan on");
  irsend.sendNEC(0x31ce00ff, 32);             //Sending the HEX code for fan on/off
  delay(1000);
}

void light()
{ 
  Serial.println("light on");
  irsend.sendNEC(0x31ce40bf, 32);           //Sending the HEX code for light on/off
  delay(1000);
}

void spd1()
{ 
  Serial.println("fan speed = 1");
  irsend.sendNEC(0x31ce20df,32);           //Sending the HEX code for fan speed 1
  delay(1000);
}

void spd2()
{ 
  Serial.println("fan speed = 2");
  irsend.sendNEC(0x31ce10ef,32);           //Sending the HEX code for fan speed 2
  delay(1000);
}

void spd3()
{ 
  Serial.println("fan speed = 3");           //Sending the HEX code for fan speed 3
  irsend.sendNEC(0x31ce609f,32);
  delay(1000);
}

void spd4()
{ 
  Serial.println("fan speed = 4");
  irsend.sendNEC(0x31cee01f, 32);           //Sending the HEX code for fan speed 4
  delay(1000);
}

void setup()
{
Serial.begin(9600);
pinMode(12,INPUT);                //Pin mode is defined to INPUT(read the state HIGH or LOW)
pinMode(11,INPUT);                //Pin mode is defined to INPUT(read the state HIGH or LOW)
pinMode(9,INPUT);                //Pin mode is defined to INPUT(read the state HIGH or LOW)
pinMode(8,INPUT);                //Pin mode is defined to INPUT(read the state HIGH or LOW)
pinMode(7,INPUT);                //Pin mode is defined to INPUT(read the state HIGH or LOW)
pinMode(6,INPUT);                //Pin mode is defined to INPUT(read the state HIGH or LOW)
}

void loop()
{
  f=1;                                // variable to determine if fan's button is pressed
  l=1;                                // variable to determine if light's button is pressed
  s1=1;                                // variable to determine if speed_1's button is pressed
  s2=1;                                //variable to determine if speed_2's button is pressed
  s3=1;                                //variable to determine if speed_3's button is pressed
  s4=1;                                //variable to determine if speed_4's button is pressed
  Serial.println();                                //leaving an empty line                  
  Serial.println();                                //leaving an empty line
  Serial.println("Code has began");               //to determine that the code has begun from start again
  f = digitalRead(12);                            //pin 12 is used to determine the state (HIGH or LOW) for fan on or off
  l = digitalRead(11);                            //pin 11 is used to determine the state (HIGH or LOW) for light on or off
  s1 = digitalRead(9);                            //pin 9 is used to determine the state (HIGH or LOW) for speed 1
  s2 = digitalRead(8);                            //pin 8 is used to determine the state (HIGH or LOW) for speed 2
  s3 = digitalRead(7);                            //pin 7 is used to determine the state (HIGH or LOW) for speed 3
  s4 = digitalRead(6);                            //pin 6 is used to determine the state (HIGH or LOW) for speed 4
  Serial.print("f before= ");
  Serial.println(f);                              // print the state of fan button (on/off)
 delay(5);
 Serial.print("l before= ");
 Serial.println(l);                              //print the state of the light button (on/off)
  delay(5);
 Serial.print("s1 before= ");
 Serial.println(s1);                              //print the state of speed_1
  delay(5);
 Serial.print("s2 before= ");
 Serial.println(s2);                              //print the state of speed_2                              
  delay(5);
 Serial.print("s3 before= ");
 Serial.println(s3);                              //print the state of speed_3
  delay(5);
 Serial.print("s4 before= ");
 Serial.println(s4);                              //print the state of speed_4
  delay(5);
    delay(100);
  if(f == 0)
{
  fan();                                          // fxn "fan" is called
 exit;
}

else if(l == 0)
{
  light();                                          //fxn "light" is called
  exit;
}
else if(s1 == 0)
{
  spd1();                                          //fxn "spd1" is called
  exit;
}
else if(s2 == 0)
{
  spd2();                                          //fxn "spd2" is called
  exit;
}
else if(s3 == 0)
{
  spd3();                                          //fxn "spd3" is called
  exit;
}
else if(s4 == 0)
{
  spd4();                                          //fxn "spd4" is called
  exit;
}
else
exit;
}
