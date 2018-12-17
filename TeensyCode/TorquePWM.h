//Calculates and sends needed PWM to get the right torque for specified motor
void Apply_torque64(float torque_val, int id64){
  float meas_speed64;
  float  PWM_64 = torque_val*2.56;//+meas_speed64*0.17;
  float  Current_64 = torque_val*0.9259259;
  int PWMset64 = PWM_64*73.75;
   if (PWM_64<=12 && PWM_64>=-12)
    {
        sendWriteInstruction4(id64, 100, PWMset64);
        delay(wDelay);
    }
}

//Calculates and sends needed PWM to get the right torque on MX 106 
void Apply_torque106(float torque_val){
  float meas_speed106;
  float PWM_106 = torque_val*1.6;//+meas_speed106*0.26;
  int PWMset106 = PWM_106*73.75;

   if (PWM_106<=12 && PWM_106>=-12)
    {
        sendWriteInstruction4(2, 100, PWMset106);
        delay(wDelay);
    }
}
