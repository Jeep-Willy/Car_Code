// RadioHead ReliableDatagram & NRF24 Libraries
#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
 
// dependant SPI Library 
#include <SPI.h>
 
// Servo Library
// #include <Servo.h>

// addresses for radio channels
#define CLIENT_ADDRESS 1   
#define SERVER_ADDRESS 2
 
// Servo Object
// Servo myServo;

// Motor Connections
int enA = 9;
int in1 = 7;
int in2 = 4;
 
// Servo Connections
// int enB = 5;
// int in3 = 7;
// int in4 = 6;
 
// Create an instance of the radio driver
RH_NRF24 RadioDriver;
 
// Sets the radio driver to NRF24 and the server address to 2
RHReliableDatagram RadioManager(RadioDriver, SERVER_ADDRESS);
 
// Define a message to return if values received
uint8_t ReturnMessage[] = "JoyStick Data Received"; 
 
// Define the Message Buffer
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
 

//  function prototypes
void receiveData();
void motorControl();
