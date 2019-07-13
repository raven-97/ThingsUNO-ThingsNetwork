# ThingsUNO-ThingsNetwork
Intro to LoRa & LoRaWAN using-Things Uno and The Things Network (TTN)


Things Uno is an Arduino Leonardo board interfaced with a radio chip making it an ideal development board for LoRa.
For actual deployment purpose You may find something which is low power consuming.


You have to make an account in TTN and establish a connection between your Things-Uno and your gateway using OTAA or ABP.
The documentation for doing the same is available in their website.
Also don't forget to install the things network library.

Setting up the Arduino IDE

In tools -> boards -> select Ardunio Leonardo
In tools -> programmer -> select ArduinoISP.

Now you are almost done.

The thing you have to know is that the permitted frequencies for LoRa is diidferent in different Countries.
So you have to set your board to usable frequency range before you can get started.

Frequency MHz	Country or Region	Default Frequencies MHz
if any
433-434	EU	433.175, 433.375, 433.575
470-510	China	
779-787	China	779.5, 779.7, 779.9
863-870	EU	868.1, 868.3, 868.5
865-867	India	865.0625, 865.4025, 865.985
902-928	USA	
915-928	Australia	
915-928	New Zealand	923.2, 923.4
920-923	South Korea	922.1, 922.3, 922.5
920-925	Hong Kong	923.2, 923.4
920-925	Singapore	923.2, 923.4
920-925	Thailand	923.2, 923.4
920-925	Vietnam	923.2, 923.4
920-928	Japan	923.2, 923.4
922-928	Taiwan	923.2, 923.4
923-925	Brunei	923.2, 923.4
923-925	Cambodia	923.2, 923.4
923-925	Indonesia	923.2, 923.4
923-925	Laos	923.2, 923.4

In the Arduino world programs ypu have to change 'freqPlan' depennding on the usable frequency.
eg: for europe Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915 for USA.


In India the freqPlan is TTN_FP_IN865_867.

You will get the nwkSKey, devAddr,appSKey from the TTN website after you registered your device.
Update those values in the program.




