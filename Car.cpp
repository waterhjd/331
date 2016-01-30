#include "Car.h"

#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>

#include "ImageLoader.h" 
class ImageLoader;

void Car::left ()
{
   m_direction += 0.1;
}
void Car::right ()
{
   m_direction -= 0.1;
}

void Car::display ()
{
   //displayWireFrame ();
   //displaySolidCube ();
   displayTexture ();
}

void Car::displayWireFrame ()
{
   glTranslatef(m_x, m_y, -5.0f);
   glRotatef(m_xangle, 1.0f, 0.0f, 50.0f);
   glRotatef(m_yangle, 0.0f, 1.0f, 0.0f);
   glutWireCube(50.0);
}
void Car::displaySolidCube ()
{
   // set the material to red
   GLfloat redDiffuseMaterial[] = {1.0, 0.0, 0.0}; 
   GLfloat blueDiffuseMaterial[] = {0.3, 0.5, 1.0}; 
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blueDiffuseMaterial);

   //By default, the light in OpenGL is white and is coming from the Z direction.  
   //We'll always use a 4D vector to describe the position of a light.  
   //The vector has values x, y, z, and w.  
   //If w is 1.0, we are defining a light at a point in space. 
   //If w is 0.0, the light is at infinity.
   GLfloat light0Position[4] = {0, 1, -1, 0};
   glLightfv(GL_LIGHT0, GL_POSITION, light0Position);

   //Here is a good site for setting up the lights:
   // http://www.swiftless.com/tutorials/opengl/material_lighting.html
   //
   glEnable (GL_LIGHTING);
   //set the light specular to white
   GLfloat whiteSpecularLight[] = {1.0, 1.0, 1.0}; 
   //set the light ambient to black
   GLfloat blackAmbientLight[] = {0.0, 0.0, 0.0};
   //set the diffuse light to white
   GLfloat whiteDiffuseLight[] = {1.0, 1.0, 1.0};

   //Now assign the colours to the current light
   glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
   glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);

   glTranslatef(m_x, m_y, -5.0f);
   glRotatef(m_xangle, 1.0f, 0.0f, 0.0f);
   glRotatef(m_yangle, 0.0f, 1.0f, 0.0f);
   glutSolidCube(50.0);
}

void Car::displayTexture ()
{
   // Draw the car
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_carTexture);
   ImageLoader::drawBox(50, GL_POLYGON, m_x, m_y, m_xangle, m_yangle);
   //ImageLoader::rectangle(m_x,m_y, 50, 50);
   glDisable(GL_TEXTURE_2D);
   glFlush();

   glFlush();
}
void Car::update ()
{
   m_xangle++;
   m_yangle+=2;
   m_x += m_speed*cos(m_direction);
   m_y += m_speed*sin(m_direction);
}

void Car::init()
{
   m_carTexture= ImageLoader::LoadTexture( "./imgs/car.bmp" );
}


Car::Car(int x, int y)
{
   m_x=x;
   m_y=y;
   m_xangle = 0;
   m_yangle = 0;
   m_direction;
   m_speed = 2;
}

