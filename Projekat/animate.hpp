#ifndef ANIMATE_HPP
#define ANIMATE_HPP value

//Funkcija koja nam sluzi za animaciju
void idle ()
{
	if ( DayOfYear >= 366 )
		DayOfYear = 0.0;

	HourOfDay += Increment;
	DayOfYear += Increment / 24.0;
	DayOnSun  += Increment / 24.0;

	if ( HourOfDay >= 24 )
		HourOfDay = 0.0;

	if ( DayOfYear >= 366.0 )
		DayOfYear = 0.0;
	//printf("%f\n", DayOfYear);
	//printf("%d\n", texBool);
	//printf("%f\n",x);
	glutPostRedisplay();
}
#endif // ANIMATE_HPP
