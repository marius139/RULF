
int timerMyo=0;

int cycleTime = 0;

int timestampMyo=0;
int myoRead = 0;
int selectMyo = 1;
// Takes in an integer from the serial communication with the PC
//Uses the integer to determine the command executed by the CrustCrawler

void serialClear(){
  while(Serial.available()){
       int ups=Serial.read();
  }
}

void signalHandling(){

       timerMyo = millis();
       
        while(Serial.available()){
        
       //Serial.println("CycleTime");
       //Serial.println(millis()-cycleTime);

       myoRead=Serial.read();

      switch(myoRead){
           
        case 0:
        trajectory(0);
        break;

        case 1:
        gripperCommands();
        trajectory(0);
        break;

        case 2:
        trajectory((selectMyo*2)-1);
        break;
     
        case 3:
        trajectory(selectMyo*2);
        break;

        case 4:
        if (timerMyo>(timestampMyo+2000)){
          
          if(selectMyo<3){

            selectMyo = selectMyo+1;
            timestampMyo = millis();
            
            }
          }
        break;

        case 5:
         if (timerMyo>(timestampMyo+2000)){
          
          if(selectMyo>1){

            selectMyo = selectMyo-1;
            timestampMyo = millis();
            
            }
          
          }
        break;
        }
        serialClear();
        
     }
     serialClear();
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
     digitalWrite(selectMyo+4,HIGH);
}
