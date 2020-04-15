#ifndef WINDOW_HPP
#define WINDOW_HPP

//Display funkcija
void display()
{
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity ();

	if( printBool )
	{
		printf ( "-------------------------------" );
		printf ( "--------------------------------------\n");
		printf ( "Double the length of the day by" );
		printf ( " clicking the left button on the mouse.\n" );
		printf ( "-------------------------------" );
		printf ( "--------------------------------------\n");
		printf ( "Halve  the length of the day by" );
		printf ( " clicking the left button on the mouse.\n" );
		printf ( "-------------------------------" );
		printf ( "--------------------------------------\n");
		printf ( "Click 'o' or 'O' for Ortho projection.       \n" );
		printf ( "Click 'f' or 'F' for Frustum projection.     \n" );
		printf ( "Click 'p' or 'P' for Perspective projection. \n" );
		printf ( "-------------------------------" );
		printf ( "--------------------------------------\n");
		printf ( "Click '1' to turn ON  the lighting.\n" );
		printf ( "Click '0' to turn OFF the lighting.\n" );
        printf ( "-------------------------------" );
		printf ( "--------------------------------------\n");
		printf ( "Click '+' to ZOOM IN .\n" );
		printf ( "Click '-' to ZOOM OUT.\n" );
		printf ( "-------------------------------" );
		printf ( "--------------------------------------\n" );
		printf ( "Click 'T' to turn ON  the textures.\n" );
		printf ( "Click 't' to turn OFF the textures.\n" );
		printf ( "-------------------------------" );
		printf ( "--------------------------------------\n" );
		printf ( "Click 'r' or 'R' to restart simulation.\n" );
		printf ( "Click 'ESC' to end the simulation.\n");
		printf ( "-------------------------------" );
		printf ( "--------------------------------------\n");

		printBool = 0;
	}
	//Poziv funkcije za crtanje elemenata
	draw ();
}

void init ()
{
	glClearColor ( 0.0 , 0.0 , 0.0 , 0.0 );
	glEnable ( GL_DEPTH_TEST );

}

//Funkcija reshape
void reshape ( int w, int h )
{
	if ( h == 0 ) h = 1;
	if ( w == 0 ) w = 1;
	glViewport( 0 , 0 , w , h);

	ScreenWidth  = w;
	ScreenHeight = h;
	if ( ViewBool )
	{
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity ();
		gluPerspective ( 70.0 ,(float)w/(float)h,  1.0  , 30.0);
		glMatrixMode ( GL_MODELVIEW );
	}
}

//Funkcija za povratak na pocetne vrijednosti
void reset ()
{
	Increment =  1.0;
	ViewBool  =  1;
	lightBool =  0;
	texBool   =  0;
    z = -10.0;
	reshape ( ScreenWidth, ScreenHeight );
}

void Ortho ()
{
	glMatrixMode   ( GL_PROJECTION );
	glLoadIdentity ();
	glOrtho        ( -6.0 , 8.0 , -6.0 , 8.0 , -100.0 , 100.0 );
	glMatrixMode   ( GL_MODELVIEW );
	ViewBool = 0;
}

void Frustum ()
{
	glMatrixMode   ( GL_PROJECTION );
	glLoadIdentity ();
	glFrustum      ( -3.0 , 4.0 , -4.0 , 2.0 , 2.5 , 100.0 );
	glMatrixMode   ( GL_MODELVIEW );
	ViewBool = 0;
}

void resetView ()
{
	ViewBool =  1;
	reshape ( ScreenWidth , ScreenHeight );
}

void LightOff ()
{
	lightBool = 0;
	texBool = 0;
	glDisable (GL_COLOR_MATERIAL);
}

void LightOn ()
{
	lightBool = 1;
	texBool = 0;
	glEnable ( GL_COLOR_MATERIAL );

}

void TextureOn ()
{
	texBool = 1;
	lightBool = 1;
	reshape ( ScreenWidth , ScreenHeight );
}

void TextureOff ()
{

	if(lightBool == 1 && texBool == 0)
        lightBool = 1;
    else
        lightBool = 0;
	texBool = 0;
	reshape ( ScreenWidth , ScreenHeight );
}

//Funkcija za tastaturu
void kbd (unsigned char key , int x , int y)
{
	switch( key )
	{
		case 27  :
			 exit ( 0 );
			 break;
		case 'o' :
		case 'O' :
			Ortho ();
			break;
		case 'R' :
		case 'r' :
			reset ();
			break;
		case 'f' :
		case 'F' :
			Frustum ();
			break;
		case 'P' :
		case 'p' :
			resetView ();
			break;
		case '0' :
			LightOff ();
			break;
		case '1' :
			LightOn ();
			break;
		case 'T' :
			TextureOn ();
			break;
		case 't' :
			TextureOff ();
			break;
        case '+' :
            z += 0.1;
            break;
        case '-' :
            z -= 0.1;
            break;
		}
}
#endif // WINDOW_HPP
