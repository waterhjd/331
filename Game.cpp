#include "Game.h"
#include <cstdio>

#include <stdlib.h>
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <time.h>
#include <GL/freeglut.h>

#include "Car.h"

#include "ImageLoader.h"

bool Game::c_running = false;


// We do not use this function yet, but you might want it.
GLfloat Game::frand() {
    return random()/(GLfloat)RAND_MAX;
}

// Called by Game::idle this function sends a signal to update the screen
void Game::timer(int id)
{
   if(id == 513)
   {
      // Redisplay frame
      glutPostRedisplay();
   }
}

// Tis function 
void Game::idle() {
   glutTimerFunc(Game::c_interval, // in this many miliseconds
     Game::timer,      // call the funtion timer
     513               // with this parameter
   );
}

void Game::run() {


    Game::getInstance().update();   
    // flush the graphics pipele and display the objects we have specified
    //Since we are using double buffering this means we swap the buffer be just drew
    //on to the screen.
    glutSwapBuffers();
    Game::idle();
}


void Game::key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case ' ' :
            Game::c_running = !Game::c_running;
            break;
        case 'n' :
            Game::getInstance().m_myCar.left();
            break;
        case 'm':
            Game::getInstance().m_myCar.right();
            break;
    }
    //glutPostRedisplay();
}

void Game::splashScreen()
{
   // Other parts of the program have been doing speical things with
   // lights and textures. We want a flat rectangle so turn them all off.
   glDisable(GL_TEXTURE_2D); // Disable any textures. We want color!
   glDisable (GL_LIGHTING);  // Also turn off any lights
   glLoadIdentity();//load identity matrix

   glEnable(GL_COLOR_MATERIAL); // Needed so glColor3f controls the color
   glColor3f(0.5f,0.7f,1.0f); //sky blue backcground
   ImageLoader::rectangle(20, 20, m_width-40, m_height-40);

   char string[1200];
   sprintf(string, "Game Paused. Press space to continue.\n");
   sprintf(string, "%s\nThis splash screen should tell you what each of the keys do.", string);
   sprintf(string, "%s\nFor example: ", string);
   sprintf(string, "%s\n    m= Turn Right ", string);
   sprintf(string, "%s\n    n= Turn Left ", string);
   glColor3f(0.0, 0.0, 0.0); // Black Text
   ImageLoader::RenderString(30, m_height-60, GLUT_BITMAP_TIMES_ROMAN_24, string);
   glDisable(GL_COLOR_MATERIAL);
}

void Game::update()
{
   // Clear color and depth buffers
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

   //clear the screen
   glClearColor(1.0, 1.0, 1.0, 0.0); // Set the clear color to white
   glClear(GL_COLOR_BUFFER_BIT);     // clear the screen

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   // Draw the background
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_backgroundTexture);
   ImageLoader::rectangle(0,0, m_width, m_height);
   glDisable(GL_TEXTURE_2D);
   glFlush();

   if(!Game::c_running)
   {
      return splashScreen();
   }

   m_myCar.update();
   m_myCar.display();
}


/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void Game::reshape(GLsizei newwidth, GLsizei newheight) 
{  
    // Set the viewport to cover the new window
     glViewport(0, 0, m_width=newwidth, m_height=newheight);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(0.0, m_width, m_height, 0.0, 0.0, 100.0);
     glMatrixMode(GL_MODELVIEW); 
     glutPostRedisplay();
}




void Game::init() {
    // Set the seed for the random variable generator just in case we need it.
    srandom(time(NULL));

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); // Use double buffering for smoother images
    glutInitWindowSize(m_width, m_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Indi 500");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(0, m_width+m_margine, 0, m_height+m_margine);
    glOrtho(0, m_width+m_margine, 0, m_height+m_margine, 0, 1000);

   //In event-driven programming, like you have in interactive OpenGL 
   //applications, the main application loop generally does three things:
   //  1. check the current event queues, and process any events (e.g., 
   //     mouse movement, key presses, etc.) that have occurred since the last check
   //  2.update the application state - things like player and object positions, 
   //    game physics, etc. - in preparation of the next rendering frame
   //  3.render the current frame.
   // GLUT does these steps implicitly in its glutMainLoop()

   // Set up the callbacks that will be taken care of in step 1:
    glutKeyboardFunc(Game::key); // Keyboard input
    glutDisplayFunc(Game::run);  // Display frames
    //glutIdleFunc(Game::run);    // Wait time between frames.


   m_backgroundTexture= ImageLoader::LoadTexture( "./imgs/background.bmp" );
   m_myCar.init();

    glutMainLoop(); // glutMainLoop enters the GLUT event processing loop. 
                    //This routine should be called at most once in a GLUT program. 
                    //Once called, this routine will never return. 
                    //It will call as necessary any callbacks that have been registered.
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    Game::getInstance().init();
}
