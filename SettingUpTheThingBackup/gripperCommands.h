
int sel=1;
int tdelay=10;
int counter=0;
int timer=0;
unsigned long timestamp = 0;

//Create a function which takes the input for signal of 1 and 2 from myo.
void gripperCommands(){

timer = millis();
if (timer>(timestamp+5000)){
  if(sel==0){
        sendWriteInstruction4(4, 116, 3072);
        delay(tdelay);
        sendWriteInstruction4(5, 116, 1024);
        delay(20);
        sel=1; 
        timestamp = millis();
        }
       else if(sel==1){
        sendWriteInstruction4(4, 116, 2125);
        delay(tdelay);
        sendWriteInstruction4(5, 116, 1975);
        delay(20);
        sel=0;
        timestamp = millis();
        }
}
}
