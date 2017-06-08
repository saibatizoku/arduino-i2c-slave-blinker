Arduino I2C Slave: LED Blinker
==============================

Very simple Arduino code that configures it as an I2C slave that blinks the built-in LED when it receives `0x01`, turning it off when it gets `0x00`.

This program was tested with receiving commands from [hello-i2c-pi](https://github.com/saibatizoku/hello-i2c-pi), as the master.

To run this program, you need to have the "Wire" library in your Arduino installation, then you can install by cloning this repository into your corresponding Arduino directory. Usually something like:

```
cd ~/Arduino
git clone https://github.com/saibatizoku/arduino-i2c-slave-blinker.git
```

Once you have the code, simply upload it to your favourite board and hook it up to a proper master.
