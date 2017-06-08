// Arduino I2C slave - LED Blinker
// by saibatizoku <http://github.com/saibatizoku>
//
// Inspired by "Wire Slave Receiver"
// by Nicholas Zambetti <http://www.zambetti.com>
//
// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Turns the built-in LED on and off upon command.

// Created 07 June 2017

// This example code is in the public domain.


#include <Wire.h>
byte SLAVE_ADDRESS = 8;
byte COMMAND_LED_ON = 0x01;
byte COMMAND_LED_OFF = 0x00;
bool LED_STATUS;
int LED_TIME_LOW = 680;
int LED_TIME_HIGH = 320;

void setup() {
  LED_STATUS = true;
  Wire.begin(SLAVE_ADDRESS);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (LED_STATUS==true) {
    led_loop();
  } else {
    delay(100);
  }
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  byte x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
  if (x == COMMAND_LED_ON) {
    LED_STATUS = true;
  } else if(x == COMMAND_LED_OFF) {
    LED_STATUS = false;
  }
}

// the loop function runs over and over again forever
void led_loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(LED_TIME_HIGH);              // wait for LED_TIME_HIGH in millis
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(LED_TIME_LOW);               // wait for LED_TIME_LOW in millis
}
