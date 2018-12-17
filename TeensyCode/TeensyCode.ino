#include <time.h>
#include <math.h>

int wDelay = 6;

#include "CCReadWrite.h"
#include "TorquePWM.h"
#include "errorCalculation.h"
#include "gripperCommands.h"
#include "dynamics.h"
#include "Trajectory.h"
#include "signalHandling.h"

int timedelay = 10; 

void testFunction();

void changeOpMode(){
  sendWriteInstruction1(1, 11, 16);
  delay(timedelay);
  sendWriteInstruction1(2, 11, 16);
  delay(timedelay);
  sendWriteInstruction1(3, 11, 16);
  delay(timedelay);
  sendWriteInstruction1(4, 11, 3);
  delay(timedelay);
  sendWriteInstruction1(5, 11, 3);
  delay(timedelay);
}

// These are the setup/loop functions that Arduino require.
void setup()
{
  // Initialize USB serial port. (On Teensy, the baud rate is disregarded and is
  // always 12 Mbaud).
  Serial.begin(9600);

  // Initialize the Dynamixel port (RX: pin0, TX: pin1, Transmit Enable: pin2.
  // With factory default baud rate of 57.6 kbaud).
  Serial1.begin(57600);
  Serial1.transmitterEnable(2);
  torqueEnable(1, false);
  delay(timedelay); 
  torqueEnable(2, false);
  delay(timedelay);
  torqueEnable(3, false); 
  delay(timedelay);   
  torqueEnable(4, false); 
  delay(timedelay);  
  torqueEnable(5, false); 
  delay(timedelay);  

  changeOpMode();
  delay(timedelay);

  torqueEnable(1, true);
  delay(timedelay); 
  torqueEnable(2, true);
  delay(timedelay);
  torqueEnable(3, true); 
  delay(timedelay);   
  torqueEnable(4, true); 
  delay(timedelay);  
  torqueEnable(5, true); 
  delay(timedelay); 
  trajectory(0);
  errorReset();
  delay(1000);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  Serial.println("Done setup");
 }

void loop()
{
 
 signalHandling();

}

void testFunction(){
if(millis() <10000){
  trajectory(3);
  Serial.println("Traj3");
 }else if(millis()>10000 && millis()<11000){
  trajectory(0);
  errorReset();
 }else if(millis()>11000 && millis()<16000){
  trajectory(4);
  Serial.println("Traj4");
 }else if(millis()>16000 && millis()<17000){
  trajectory(0);
  errorReset();
 }else if(millis()>17000 && millis()<27000){
  trajectory(5);
  Serial.println("Traj5");
 }else if(millis()>27000 && millis()<28000){
  trajectory(0);
  errorReset();
 }else if(millis()>28000 && millis()<38000){
  trajectory(6);
  Serial.println("Traj6");
 }else if(millis()>38000 && millis()<39000){
  trajectory(0);
  errorReset();
 }else if(millis()>39000 && millis()<49000){
  trajectory(1);
  Serial.println("Traj1");
 }else if(millis()>49000 && millis()<50000){
  trajectory(0);
  errorReset();
 }else if(millis()>50000 && millis()<60000){
  trajectory(2);
  Serial.println("Traj2");
 }else{
  trajectory(0);
  errorReset();
  gripperCommands();
}
}
