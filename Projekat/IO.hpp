#ifndef IO_HPP
#define IO_HPP value

//Funkcija za mis
void mouse ( int button, int state , int x , int y )
{
	switch ( button )
	{
 		case GLUT_LEFT_BUTTON :
			Increment *= 2;
			break;
		case GLUT_RIGHT_BUTTON :
			Increment /= 2;
			break;
	}
}
#endif // IO_HPP
