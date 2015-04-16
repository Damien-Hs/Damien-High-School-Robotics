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

/////////////////////////////////////////////////////////////////////////////////////////
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


/////////////////////////////////////////////////////////////////////////////////////////
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
/////////////////////////////////////////////////////////////////////////////////////////

/*
Autonomous Task Description
<Outline your autonomous routine here>

Insert autonomous code inside the task
*/
task autonomous()
{

}


/////////////////////////////////////////////////////////////////////////////////////////
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
/////////////////////////////////////////////////////////////////////////////////////////

/*
User Control Task Description
<Outline your driver control code here>

*/

task usercontrol()
{
	// User control code here, inside the while loop

	while (true)
	{
	  // Insert user code here. This is where you use the controller joysticks and buttons to contol the robot
	}
}
