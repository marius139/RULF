int32_t ServoPos11;
int32_t ServoPos22;
int32_t ServoPos33;
int32_t VeloRead11;
int32_t VeloRead22;
int32_t VeloRead33;


float Posi1 = 0;
float Posi2 = 0;
float Posi3 = 0;
float Velo1 = 0;
float Velo2 = 0;
float Velo3 = 0;
float Acce1 = 0;
float Acce2 = 0;
float Acce3 = 0;

float Error1 = 0.0;
float Error2 = 0.0;
float Error3 = 0.0;

float tau1 = 0.0;
float tau2 = 0.0;
float tau3 = 0.0;

//Calculating the trajectory for the joint(s) and sending it to dynamics
unsigned long startTime = millis();


void trajectory(int myoIn) {

	//Reading Position and velocity
	while (readPosition(1, ServoPos11) == false) {};
	while (readPosition(2, ServoPos22) == false) {};
	while (readPosition(3, ServoPos33) == false) {};
	while (readVelocity(1, VeloRead11) == false) {};
	while (readVelocity(2, VeloRead22) == false) {};
	while (readVelocity(3, VeloRead33) == false) {};
/*
	Serial.println("Velociy");
	Serial.println(VeloRead11);
	Serial.println(VeloRead22);
	Serial.println(VeloRead33);
*/
	float the1 = ((ServoPos11*(2 * PI / 4096)) - PI);
	float the2 = ((ServoPos22*(2 * PI / 4096)) - PI);
	float the3 = ((ServoPos33*(2 * PI / 4096)) - PI);
/*
	Serial.println("Angles Radians");
	Serial.println(the1);
	Serial.println(the2);
	Serial.println(the3);
*/
	switch (myoIn) {

	case 0:
		//Staying in current position, no movement
		Posi1 = the1;
		Posi2 = the2;
		Posi3 = the3;
		Velo1 = 0;
		Velo2 = 0;
		Velo3 = 0;
		Acce1 = 0;
		Acce2 = 0;
		Acce3 = 0;

		//Calculate errors
		Error1 = Acce1 + errorPos(Posi1, the1, 1) + errorVel(Velo1, VeloRead11, 1);
		Error2 = Acce2 + errorPos(Posi2, the2, 2) + errorVel(Velo2, VeloRead22, 2);
		Error3 = Acce3 + errorPos(Posi3, the3, 3) + errorVel(Velo3, VeloRead33, 3);

		//Calculate needed torques
		tau1 = dynamics(1, Error1, Error2, Error3, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);
		tau2 = dynamics(2, Error1, Error2, Error3, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);
		tau3 = dynamics(3, Error1, Error2, Error3, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);

		//Applying torques to the motors 
		Apply_torque64(tau3, 3);
		Apply_torque106(tau2);
		Apply_torque64(0, 1);

		break;

	case 1: //Joint 1 moving Right
		if (the1 < (3*PI/4)) {

			Posi1 = the1 + 1;
			Posi2 = the2;
			Posi3 = the3;
			Velo1 = 1.4;
			Velo2 = 0;
			Velo3 = 0;
			Acce1 = 15;
			Acce2 = 0;
			Acce3 = 0;

		}
		else {

			Posi1 = the1;
			Posi2 = the2;
			Posi3 = the3;
			Velo1 = 0;
			Velo2 = 0;
			Velo3 = 0;
			Acce1 = 0;
			Acce2 = 0;
			Acce3 = 0;
		}

		Error1 = Acce1 + errorPos(Posi1, the1, 1) + errorVel(Velo1, VeloRead11, 1);
		tau1 = dynamics(1, Error1, 0, 0, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);
		Apply_torque64(tau1, 1);
		break;

	case 2: //Joint 1 moving Left
		if (the1 > (-3*PI/4)) {

			Posi1 = the1 - 1;
			Posi2 = the2;
			Posi3 = the3;
			Velo1 = -1.4;
			Velo2 = 0;
			Velo3 = 0;
			Acce1 = -15;
			Acce2 = 0;
			Acce3 = 0;

		}
		else {

			Posi1 = the1;
			Posi2 = the2;
			Posi3 = the3;
			Velo1 = 0;
			Velo2 = 0;
			Velo3 = 0;
			Acce1 = 0;
			Acce2 = 0;
			Acce3 = 0;
		}

		Error1 = Acce1 + errorPos(Posi1, the1, 1) + errorVel(Velo1, VeloRead11, 1);
		tau1 = dynamics(1, Error1, 0, 0, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);
		Apply_torque64(tau1, 1);
		break;

	case 3: //Joint 2 moving down
		if (the2 < (PI/2)+0.3) {

			Posi1 = the1;
			Posi2 = the2 + 0.2;
			Posi3 = the3;
			Velo1 = 0;
			Velo2 = 7;
			Velo3 = 0;
			Acce1 = 0;
			Acce2 = 10;
			Acce3 = 0;

		}
		else {

			Posi1 = the1;
			Posi2 = the2;
			Posi3 = the3;
			Velo1 = 0;
			Velo2 = 0;
			Velo3 = 0;
			Acce1 = 0;
			Acce2 = 0;
			Acce3 = 0;
		}

		//Calculating error
		Error2 = Acce2 + errorPos(Posi2, the2, 2) + errorVel(Velo2, VeloRead22, 2);
		Error3 = Acce3 + errorPos(Posi3, the3, 3) + errorVel(Velo3, VeloRead33, 3);

		//Calculating torque
		tau2 = dynamics(2, 0, Error2, 0, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);
	  tau3 = dynamics(3, 0, 0, Error3, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);

		//Applying torque
		Apply_torque64(tau3, 3);
		Apply_torque106(tau2*0.5);
		break;

	case 4: //Joint 2 moving up
		if (the2 > 0) {

			Posi1 = the1;
			Posi2 = the2 - 0.8;
			Posi3 = the3;
			Velo1 = 0;
			Velo2 = -2;
			Velo3 = 0;
			Acce1 = 0;
			Acce2 = -10;
			Acce3 = 0;

		}
		else {

			Posi1 = the1;
			Posi2 = the2;
			Posi3 = the3;
			Velo1 = 0;
			Velo2 = 0;
			Velo3 = 0;
			Acce1 = 0;
			Acce2 = 0;
			Acce3 = 0;
		}
		//Calculating error
		Error2 = Acce2 + errorPos(Posi2, the2, 2) + errorVel(Velo2, VeloRead22, 2);
		Error3 = Acce3 + errorPos(Posi3, the3, 3) + errorVel(Velo3, VeloRead33, 3);

		//Calculating torque
		tau2 = dynamics(2, 0, Error2, 0, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);
		tau3 = dynamics(3, 0, 0, Error3, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);

		//Applying torque
		Apply_torque64(tau3, 3);
		Apply_torque106(tau2*1.3);
		break;

	case 5://Joint 3 moving down
		if (the3 < PI/2) {

			Posi1 = the1;
			Posi2 = the2;
			Posi3 = the3+ 0.5;
			Velo1 = 0;
			Velo2 = 0;
			Velo3 = 25;
			Acce1 = 0;
			Acce2 = 0;
			Acce3 = 20;

		}
		else {

			Posi1 = the1;
			Posi2 = the2;
			Posi3 = the3;
			Velo1 = 0;
			Velo2 = 0;
			Velo3 = 0;
			Acce1 = 0;
			Acce2 = 0;
			Acce3 = 0;
		}
		//Calculating error
		Error2 = Acce2 + errorPos(Posi2, the2, 2) + errorVel(Velo2, VeloRead22, 2);
		Error3 = Acce3 + errorPos(Posi3, the3, 3) + errorVel(Velo3, VeloRead33, 3);

		//Calculating torque
		tau2 = dynamics(2, 0, Error2, 0, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);
		tau3 = dynamics(3, 0, 0, Error3, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);

		//Applying torque
		Apply_torque64(tau3*0.5, 3);
		Apply_torque106(tau2);
		break;

	case 6://Joint 3 moving up
		if (the3 > 0) {

			Posi1 = the1;
			Posi2 = the2;
			Posi3 = the3-0.5;
			Velo1 = 0;
			Velo2 = 0;
			Velo3 = -1;
			Acce1 = 0;
			Acce2 = 0;
			Acce3 = -10;

		}
		else {

			Posi1 = the1;
			Posi2 = the2;
			Posi3 = the3;
			Velo1 = 0;
			Velo2 = 0;
			Velo3 = 0;
			Acce1 = 0;
			Acce2 = 0;
			Acce3 = 0;
		}
		//Calculating error
		Error2 = Acce2 + errorPos(Posi2, the2, 2) + errorVel(Velo2, VeloRead22, 2);
		Error3 = Acce3 + errorPos(Posi3, the3, 3) + errorVel(Velo3, VeloRead33, 3);

		//Calculating torque
		tau2 = dynamics(2, 0, Error2, 0, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);
		tau3 = dynamics(3, 0, 0, Error3, VeloRead11, VeloRead22, VeloRead33, the1, the2, the3);

		//Applying torque
		Apply_torque64(tau3*1.5, 3);
		Apply_torque106(tau2);
		break;
	}

/*
  Serial.println("Error");
  Serial.println(Error1);
  Serial.println(Error2);
  Serial.println(Error3);
 */
}
