#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

#include "planets.hpp"
#include "window.hpp"
#include "animate.hpp"
#include "IO.hpp"
#include "texture.hpp"

int main (int argc, char * argv [])
{
	//Inicijaliziramo glut
	glutInit            ( &argc , argv );
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	//Inicijalizacija pozicije i velicine prozora
	glutInitWindowPosition (  0  ,  0  );
	glutInitWindowSize     ( 600 , 400 );
	glutCreateWindow ("Zavrsni projekat");

	init ();

	//Inicijalizacija funkcija
	glutReshapeFunc  (reshape);
	glutKeyboardFunc (kbd);
	glutDisplayFunc  (display);
	glutMouseFunc    (mouse);
	glutIdleFunc     (idle);

	glutMainLoop ();

	return 0;
}
