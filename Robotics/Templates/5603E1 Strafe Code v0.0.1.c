/****************************************************************************************************************************************************
6526D-5603E1
Tilt Strafe Code Repository
****************************************************************************************************************************************************/
task main()
{
	while(1 == 1)
	{
		//STRAFE CONTROL

		int STRFthreshold;

		STRFthreshold = 15;

		while(abs(vexRT[AccelX]) > STRFthreshold)
		{
			if(vexRT[AccelX] < (-1 * STRFthreshold)) //controller tilted LEFT beyond threshold (NEGATIVE value)
			{
				motor[STRF] = -127;
			}
			if(vexRT[AccelX] > (STRFthreshold)) //controller tilted RIGHT beyond threshold (POSITIVE value)
			{
				motor[STRF] = 127;
			}
		}
	}


}
