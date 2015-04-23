#pragma config(Motor,  port1,           dRF,           tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           dLF,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           dLR,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          dRR,           tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//***************************************************************************************
//														Damien Robotics Academy
//																Code Template
//***************************************************************************************

/*
Team:
Robot:
Code Version:
Date:
*/

void pre_auton()
{}

task autonomous()
{}

task driveCode();

task usercontrol()
{
	startTask(driveCode);

	while (true)
	{

	}
}

task driveCode()
{
	int accel_x   = 0;    				  // Will hold the controller-accelerometer X reading.
	int accel_y   = 0;    				  // Will hold the controller-accelerometer Y reading.

	int prev_x    = 0;     					// Will hold the previous accelerometer X reading (for comparison).
	int prev_y    = 0;    			  	// Will hold the previous accelerometer Y reading (for comparison).

	const int driveScale = (2);			// Scale the motor speed

	const int drive_refresh = 10;		// Calculation period: wait ## milliseconds to refresh speed values

	int threshold = 6;    					// Used to eliminate the effect of small tilt values

	while(1 == 1)
	{
		prev_x = accel_x;         	  // update previous x reading to 'accel_x'
		prev_y = accel_y;         	  // update previous y reading to 'accel_y'
		accel_x = vexRT[AccelX];   		// update 'accel_x' to new current reading
		accel_y = vexRT[AccelY];    	// update 'accel_y' to new current reading

		// is abs(current - prev) < threshold?
		if( (abs(accel_x - prev_x) < threshold) || (abs(accel_y - prev_y) > threshold) )
		{
			// Are either of them > threshold?
			if( (abs(accel_x) > threshold) || (abs(accel_y) > threshold) )
			{
				// YES.
				if(accel_y > 0)						// going backwards?
				{
					motor[dLF]  = ( ((-1 * accel_y) - accel_x)/2 ) * (driveScale);
					motor[dLR]  = ( ((-1 * accel_y) - accel_x)/2 ) * (driveScale);
					motor[dRF] = ( ((-1 * accel_y) + accel_x)/2 ) * (driveScale);
					motor[dRR] = ( ((-1 * accel_y) + accel_x)/2 ) * (driveScale);
				}
				else  										// going forward, or point turn:
				{
					motor[dLF]  = ( ((-1 * accel_y) + accel_x)/2 ) * (driveScale);
					motor[dLR]  = ( ((-1 * accel_y) + accel_x)/2 ) * (driveScale);
					motor[dRF] = ( ((-1 * accel_y) - accel_x)/2 ) * (driveScale);
					motor[dRR] = ( ((-1 * accel_y) - accel_x)/2 ) * (driveScale);
				}
			}
			else												// If the values are less than the threshold
			{
				motor[dLF] = 0;
				motor[dLR] = 0;
				motor[dRF] = 0;
				motor[dRR] = 0;
			}
		}


		//Speed assignment limiter
		if(motor[dLF] > 127)
		{
			motor[dLF] = 127;
		}
		if(motor[dLR] > 127)
		{
			motor[dLR] = 127;
		}
		if(motor[dRF] > 127)
		{
			motor[dRF] = 127;
		}
		if(motor[dRR] > 127)
		{
			motor[dRR] = 127;
		}

		wait1Msec( drive_refresh );   // Wait "drive_refresh" ms to refresh speed assignment
	}
}
