# Arduino-IR-remote-
Replicating IR-tech based remote 


Library used : https://github.com/z3t0/Arduino-IRremote
Although I've been coding for a couple of years this is my first github project.

So I got inspired to do this project after my Dad's celing fan remote gone bad it's an orient company's ceiling fan. I own an Android which has an IR transmitter. Years back just for fun I saved the IR codes of the celing fan button codes. Never thought I'd ever have the need to use it. 
During the quarantine(due to corona virus out-break) I've been spending my entire day at my house. So I decided to make the remote.

After this being said Let's start with the porject.

I started with obtaining the HEX codes on which the fan operates. For that I used an IR-transistor. 
my ceiling fan operates on the 40hz frequency and requires an appropriate HEX to do the specific task (eg: turn on/off the fan, chhange the speed turn on the light).

I have made separates funtions to perform the task, light fxn looks something like this:

 light()                                    // function initiates
{ 
  Serial.println("light on");               //Print data on serial monitor to know we're in which fxn: this will be removed later//
  irsend.sendNEC(0x31ce40bf, 32);           //IR_library is initiated and sending the data using NEC(similar to: sony, panasonic etc)//
  delay(60);                                // delay in miliseconds//
  Serial.println("in light's fxn");         //Print data on serial monitor to know we're in which fxn: this will be removed later//
  delay(1000);                              //delay in miliseconds//
}

NOTE: I have made several changes in the (ir_NEC.cpp) file and changed the frequency from 38 to 40 to serve my purpose.

You have to choose the correct remote type which suites your purpose. eg: for my purpose HEX code need to be of 32-bits.
PS: In the future I'll be working on making this device more robust and campatible with a lot more devices (eg: Air-conditioner, Television etc.)


About the circuit Diagram: I am working on my circuit schematic skills:

According to the code:

                      |         pin No.            |                        Task to be performed                  |
                      |                            |   if Button not pressed   |      If button is pressed        |
                      |           12               |PULLED HIGH(Nothing)       | Set to ground(turn fan On/off)   |
                      |           11               |PULLED HIGH(Nothing)       | Set to ground(turn light on/off) |
                      |            9               |PULLED HIGH(Nothing)       | Set to ground(fan speed = 1)     |
                      |            8               |PULLED HIGH(Nothing)       | Set to ground(fan speed = 2)     |
                      |            7               |PULLED HIGH(Nothing)       | Set to ground(fan speed = 3)     |
                      |            6               |PULLED HIGH(Nothing)       | Set to ground(fan speed = 4)     |


                       |        pin No.            |                                Task to be performed                              |
                       |           3               |IR-LED is connected to this pin and will send HEX codes                           |
                       |           2               |It is the status LED it BLink for a second & indicates that IR-LED is sending data|
