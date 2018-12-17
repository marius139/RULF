float ErrorOld1 = 0;
float ErrorOld2 = 0;
float ErrorOld3 = 0;
float ErrorOld1V = 0;
float ErrorOld2V = 0;
float ErrorOld3V = 0;
float IErrorP1 = 0;
float IErrorP2 = 0;
float IErrorP3 = 0;
float IErrorV1 = 0;
float IErrorV2 = 0;
float IErrorV3 = 0;
float LastCalc1 = 0;
float LastCalc2 = 0;
float LastCalc3 = 0;
float LastCalc1V = 0;
float LastCalc2V = 0;
float LastCalc3V = 0;


void errorReset (){
 //Resetting variables for new calculations
 IErrorP1 = 0;
 IErrorP2 = 0;
 IErrorP3 = 0;
 IErrorV1 = 0;
 IErrorV2 = 0;
 IErrorV3 = 0;

 LastCalc1 = millis();
 LastCalc2 = millis();
 LastCalc3 = millis();
 LastCalc1V = millis();
 LastCalc2V = millis();
 LastCalc3V = millis();
}

//Read current position of the dynamixel with selected id
float errorPos(float TrajectoryPos, float ServoPos, int id){
  float Output = 0.0;
  
  if (id == 1) {
    float Kp = 14.67;
    float Ki = 0.0;
    float Kd = 0;
	  float Time = (millis() - LastCalc1)/1000.0;
    LastCalc1 = millis();
	  IErrorP1 += (TrajectoryPos - ServoPos)*Time;
	  Output = (TrajectoryPos - ServoPos)*Kp + (ErrorOld1 - ((TrajectoryPos - ServoPos))/Time)*Kd + IErrorP1 * Ki;
	  ErrorOld1 = TrajectoryPos - ServoPos;
  }
  else if (id == 2) {
    float Kp = 14.67;
    float Ki = 0;  
    float Kd = 0;  
	  float Time = (millis() - LastCalc2) / 1000.0;
    LastCalc2 = millis();
	  IErrorP2 += (TrajectoryPos - ServoPos)*Time;
	  Output = (TrajectoryPos - ServoPos)*Kp + (ErrorOld2 - ((TrajectoryPos - ServoPos)) / Time)*Kd + IErrorP2 * Ki;
	  ErrorOld2 = TrajectoryPos - ServoPos;
  }
  else if (id == 3) {
    float Kp = 14.67;
    float Ki = 20.0;
    float Kd = 1.0;
	  float Time = (millis() - LastCalc3) / 1000.0;
    LastCalc3 = millis();
	  IErrorP3 += ((TrajectoryPos - ServoPos) *Time);
	  Output = (TrajectoryPos - ServoPos)*Kp + (ErrorOld3 - ((TrajectoryPos - ServoPos)) / Time)*Kd + IErrorP3 * Ki;
	  ErrorOld3 = TrajectoryPos - ServoPos;
  }

return Output;
}


//Read current velocity of the dynamixels
float errorVel(float TrajectoryVel, float ServoVel, int id) {
  float Output = 0.0;

  if (id == 1) {
    float Kv = 7.66;
    float Ki = 0.0;
    float Kd = 0;
	  float Time = (millis() - LastCalc1V) / 1000.0;
    LastCalc1V = millis();
	  IErrorV1 += (TrajectoryVel - ServoVel)*Time;
	  Output = (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60)))*Kv + (ErrorOld1V - (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60))) / Time)*Kd + IErrorV1 * Ki;
	  ErrorOld1V = (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60)));
  }
  else if (id == 2) {
    float Kv = 7.66;
    float Ki = 0;
    float Kd = 0;
	  float Time = (millis() - LastCalc2V) / 1000.0;
    LastCalc2V = millis();
	  IErrorV2 += (TrajectoryVel - ServoVel)*Time;
	  Output = (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60)))*Kv + (ErrorOld2V - (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60))) / Time)*Kd + IErrorV2 * Ki;
	  ErrorOld2V = (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60)));
  }
  else if (id == 3) {
    float Kv = 7.66;
    float Ki = 0;
    float Kd = 0;
	  float Time = (millis() - LastCalc3V) / 1000.0;
    LastCalc3V = millis();
	  IErrorV3 += (TrajectoryVel - ServoVel)*Time;
	  Output = (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60)))*Kv + (ErrorOld3V - (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60))) / Time)*Kd + IErrorV3 * Ki;
	  ErrorOld3V = (TrajectoryVel - ((ServoVel*0.229)*((2 * PI) / 60)));
  }
  
  return Output;
}
