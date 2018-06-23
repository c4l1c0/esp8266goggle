# esp8266goggle
There is 2 folder in this repo, they are mostly the same. It's pretty clear from the name of the folder. So, i think it's self explanatory, but i will give you a bit of a story here. X)

When i prototyped this project, i used max7219 LED matrix driver. Then my "boss" asked to make one with blue LEDs, so i ordered new LED matrix with driver included (AND FREAKING SOLDERED! WHY?!). I uploaded my max7219 code there and voila, it didnt works. I took my flashlight and pointed it at the IC, surprise surprise, it's not max7219. So after a few hours (4 hours if i remembered correctly) of trying to squash the bug, i tried to disable rotation and setposition function and it magically works.

That's all, cheers! X)

# Library
I used markruys's max72xx library for driving the LED Matrix.

You should install the library first! Here's the link https://github.com/markruys/arduino-Max72xxPanel

# Wiring
To connect your max7219 to your esp8266 just connect it like so:
* DIN   <==>    MOSI (GPIO13)
* CLK   <==>    SCLK (GPIO14)
* CS    <==>    GPIO5

If you use NodeMCU boards, it basically the same, but i'll write it anyway:
* DIN   <==>    D7
* CLK   <==>    D5
* CS    <==>    D1

CS pin could be set to another pin by specifying it on a variable called pinCS.

# Audio Visualizer Function
I added audio visualizer function. To use it, you need to run the Processing program on your computer. Your computer need to be connected to the esp8266's access point.
