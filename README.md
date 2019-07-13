# ThingsUNO-ThingsNetwork
Intro to LoRa & LoRaWAN using-Things Uno and The Things Network (TTN)


Things Uno is an Arduino Leonardo board interfaced with a radio chip making it an ideal development board for LoRa.
For actual deployment purpose you may find something which is low power consuming.


You have to make an account in TTN and establish a connection between your Things-Uno and your gateway using OTAA or ABP.
The documentation for doing the same is available in their website.
Also don't forget to install the things network library.

Setting up the Arduino IDE

In tools -> boards -> select Ardunio Leonardo
In tools -> programmer -> select ArduinoISP.

Now you are almost done.

The thing you have to know is that the permitted frequencies for LoRa is diidferent in different Countries.
So you have to set your board to usable frequency range before you can get started.



In the Arduino programs ypu have to change 'freqPlan' depending on the usable frequency.
eg: for Europe Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915 for USA.


In India the freqPlan is TTN_FP_IN865_867.

You will get the nwkSKey, devAddr,appSKey from the TTN website after you register your device.
Update those values in the program.




