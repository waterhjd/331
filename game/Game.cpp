#include "Game.h"
#include <cstdio>

//#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>

#include "../classes/GameObject/Prop/Wall/Wall.h"
#include "../classes/GameObject/Moveable/Character/Character.h"
#include "../classes/GameObject/Moveable/Bunny/Bunny.h"
#include "../classes/GameObject/GameObject.h"

#include "../classes/ImageLoader/ImageLoader.h"

bool Game::c_running = false;
int splash_w, splash_h;

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
    Character *myCharacter = dynamic_cast<Character*>(Game::getInstance().character());
    // Character *myCharacter = Game::m_character;
   if (!Game::c_running) {
      if (key == ' ') {
         Game::c_running = true;
      }
   } else {
    switch (key)
    {
        case 'p' :
            Game::c_running = false;
            break;
        case 'h' :
				myCharacter->left();
            break;
        case 'j' :
            myCharacter->stop();
            break;
        case 'l':
				myCharacter->right();
            break;
        case 'k':
            myCharacter->jump();
            break;
    }
   }
    //glutPostRedisplay();
}

void Game::RenderString(float x, float y, void *font, const char* string)
{  
  char *c;

  const unsigned char* string2 = (const unsigned char*)string;

  glColor3f(1.0, 0.0, 0.0); 
  glRasterPos2f(x, y);

  glutBitmapString(font, string2);
}
void Game::splash() {
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   //glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
   glBindTexture (GL_TEXTURE_2D, m_splashTexture);
   ImageLoader::rectangle(0,0, m_width, m_height);

      // Other parts of the program have been doing speical things with
   // lights and textures. We want a flat rectangle so turn them all off.
   glDisable(GL_TEXTURE_2D); // Disable any textures. We want color!

   glLoadIdentity();//load identity matrix
   glEnable(GL_COLOR_MATERIAL); // Needed so glColor3f controls the color

   char string[1200];
   sprintf(string, "Paused\n");
   glColor3f(1.0, 0.0, 0.0); // Red Text
   ImageLoader::RenderString((m_width/2)-40, m_height/2, GLUT_BITMAP_TIMES_ROMAN_24, string);
   glDisable(GL_COLOR_MATERIAL);
 
}
void Game::update()
{
   m_character->update();
   for(int i=0; i<m_gameObjects; i++)
      m_myGameObjects[i]->collide(m_character);

   for(int i=0; i<m_gameObjects; i++)
      m_myGameObjects[i]->update();

   glClearColor(1.0, 1.0, 1.0, 0.0);
	 // clear the screen
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     
   // Display the current score
   char string[40];
   sprintf(string, "Score:%d\n", m_score);
   sprintf(string, "Press P to Pause\n");
   RenderString(0, m_height-20, GLUT_BITMAP_TIMES_ROMAN_24, string);


   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();


	 m_scroller->update();
   // m_left_border->collide(m_character);
	 // if (m_x_distance < m_character->get_left() - (m_width / 2)) {
		//  m_x_distance = m_character->get_left() - (m_width / 2);
	 // }
   // m_left_border->update(m_x_distance);
	 // glTranslatef(- m_x_distance, 0.0, 0.0);

   for(int i=0; i<m_gameObjects; i++)
      m_myGameObjects[i]->display();
   
   glFlush();


   if (!isRunning()) return splash();

}
bool Game::isRunning() {
   return c_running;
}

void Game::setRun(bool b) {
   c_running = b;
}


void Game::init() {

		// m_x_distance = 0;
    // m_left_border = new Border();
   
    // Set up all the objects in the game that m_character can collide with in an array
    // called m_myGameObjects. m_gameObjects tells how many are defined.
    m_gameObjects = 0 ;
		m_myGameObjects[m_gameObjects] = new Character();
		m_gameObjects ++ ;
    m_character = dynamic_cast<Character*>(m_myGameObjects[0]);

		m_scroller = new Scroller(m_character, m_width);
    
    m_myGameObjects[m_gameObjects] = new Bunny();
    m_gameObjects++;

		// floor
    m_myGameObjects[m_gameObjects] = new Wall(0,m_height/3,m_width,m_height/3);
    m_gameObjects++;

    m_myGameObjects[m_gameObjects] = new Wall(200,m_height/2,300,m_height/2);
    m_gameObjects++;

    // Set the seed for the random variable generator just in case we need it.
    srandom(time(NULL));

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); // Use double buffering for smoother images
    glutInitWindowSize(m_width, m_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cockroach vs. Unicorns");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, m_width, 0, m_height);

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

    m_splashTexture = ImageLoader::LoadTexture("./images/cvuSplash.bmp", splash_w, splash_h);

    glutMainLoop(); // glutMainLoop enters the GLUT event processing loop. 
                    //This routine should be called at most once in a GLUT program. 
                    //Once called, this routine will never return. 
                    //It will call as necessary any callbacks that have been registered.
}


