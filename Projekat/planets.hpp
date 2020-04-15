#ifndef PLANETS_HPP
#define PLANETS_HPP value
#include <math.h>
#include "texture.hpp"

float  ScreenWidth;
float  ScreenHeight;

float HourOfDay  = -1.0;
float DayOfYear  =  0.0;
float DayOnSun   =  0.0;
float Increment  =  1.0;
int   printBool  =  1;
int   ViewBool   =  1;
int   lightBool  =  0;
int   texBool    =  0;
float x = 0.0;
float z = -10.0;

//Funkcija za crtanje Sunca
void drawSun ()
{
	//Instrukcije koje sluze prilikom postavke svjetlosti
	if(lightBool == 1)
	{
		GLfloat diffuseLight  [] = { 0.658824 , 0.658824 , 0.658824 , 1.0 };
		GLfloat specularLight [] = { 1.0 , 1.0 ,  1.0 , 1.0 };
		GLfloat position      [] = { 0.0 , 0.0 , z , 1.0 };
		GLfloat position2     [] = { 0.0 , 0.0 , z/2 , 1.0 };

		glLightfv    ( GL_LIGHT1 , GL_POSITION  , position      );
		glLightfv    ( GL_LIGHT1 , GL_DIFFUSE   , diffuseLight  );
		glLightfv    ( GL_LIGHT1 , GL_SPECULAR  , specularLight );
		glLightfv    ( GL_LIGHT0 , GL_POSITION  , position2     );
        if(texBool == 0)
            glMaterialfv ( GL_FRONT  , GL_SPECULAR  , specularLight );

		glMaterialf  ( GL_FRONT  , GL_SHININESS , 150.0 );
		glColor3f    ( 1.0 , 1.0 , 0.0 );
	}
	else
	{
		glColor3f ( 0.658824  , 0.658824 ,  0.658824 );
	}


	//Postavke pozicije sunca i instrukcija za crtanje sunca
	glTranslatef    ( 0.0  , 0.0 , z );
	glRotatef       ( 20.0 , 1.0 ,  0.0 , 0.0 );
	glPushMatrix ();

	//Postavke rotacije sunca oko svoje ose
	glRotatef ( 360.0 * DayOnSun / 240.0, 0.0 , 1.0 , 0.0);

	if(texBool == 1)
	{
	    glEnable(GL_TEXTURE_2D);
        tex(1);
	}
	else
    {
        glDisable(GL_TEXTURE_2D);
        glutSolidSphere ( 1.8  , 120  ,  60  );
    }
    glPopMatrix();
	glPushMatrix    ();
}

//Funkcija za crtanje Zemlje
void drawEarth ()
{
	//Instrukcije koje sluze prilikom postavke svjetlosti
	if(lightBool == 1)
	{
	 	glDisable (GL_LIGHT0);
		glColor3f ( 0.0 , 0.38 , 0.478);
	}
	else
	{
		glColor3f ( 0.0 , 0.0 , 1.0 );
	}

	//Postavke rotacije zemlje oko sunca

	glRotatef    ( 360.0 * DayOfYear / 365.0  , 0.0 , 1.0 , 0.0 );
	glTranslatef ( 5.0 , 0.0 , 0.0 );
	glPushMatrix ();

	//Postavke rotacije zemlje oko svoje ose
	glRotatef ( 360.0 * HourOfDay / 24.0, 0.0 , 1.0 , 0.0);

	//Crtamo Zemlju
	if(texBool == 1)
	{
	    glRotatef(-90.0,1.0,0.0,0.0);
        glEnable(GL_TEXTURE_2D);
        tex(2);
	}
	else
    {
        glDisable(GL_TEXTURE_2D);
        glutSolidSphere ( 0.6 , 60  , 30);
    }
	glPopMatrix     ();
}

//Funkcija za crtanje mjeseca
void drawMoon ()
{
	//Instrukcije koje sluze prilikom postavke svjetlosti
	if(lightBool == 1)
	{
		glDisable ( GL_LIGHT0 );
		glColor3f ( 0.658824  , 0.658824 ,  0.658824 );
	}
	else
	{
		glColor3f    ( 0.2 , 0.4 , 0.4 );
	}

	//Postavke rotacije mjeseca oko zemlje
	glRotatef    ( 360.0 * 12.0 * DayOfYear / 365.0  , 0.0 , 1.0 , 1.0);
	glTranslatef ( 1.0 , 0.0 , 0.0);

	//Crtamo mjesec
	if(texBool == 1)
	{
        glEnable(GL_TEXTURE_2D);
        tex(3);
	}
	else
    {
        glDisable(GL_TEXTURE_2D);
        glutSolidSphere ( 0.18 , 30 , 15);
    }
	glPopMatrix ();
}

//Funkcija za crtanje elemenata
void draw ()
{
	//Instrukcije koje sluze prilikom postavke svjetlosti
	if(lightBool == 1)
	{
		glShadeModel ( GL_SMOOTH );
		glEnable ( GL_LIGHT1 );
		glEnable ( GL_LIGHT0 );
		glEnable ( GL_LIGHTING );
		if(texBool!=1)
            glEnable ( GL_COLOR_MATERIAL );
	}
	else
	{
	 	glDisable ( GL_LIGHT0 );
		glDisable ( GL_LIGHT1 );
		glDisable ( GL_LIGHTING );
		glDisable ( GL_COLOR_MATERIAL );
	}

	//Pozivamo funkcije koje sluze za crtanje sunca, zemlje i mjeseca
    drawSun   ();
    drawEarth ();
    drawMoon  ();
 	glutSwapBuffers ();
}
#endif // PLANETS_HPP
