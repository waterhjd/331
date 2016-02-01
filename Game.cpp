#include "Game.h"
#include <cstdio>

//#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>

#include "Wall.h"
#include "Character.h"
#include "GameObject.h"

#include "ImageLoader.h"

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
    switch (key)
    {
        case ' ' :
            if (Game::getInstance().isRunning()) Game::getInstance().setRun(true);
            break;
        case 'h' :
						myCharacter->left();
            break;
        case 'l':
						myCharacter->right();
            break;
        case 'k':
            myCharacter->jump();
            break;
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
   glColor3f(0.0, 0.0, 0.0); // Black Text
   ImageLoader::RenderString(30, m_height-60, GLUT_BITMAP_TIMES_ROMAN_24, string);
   glDisable(GL_COLOR_MATERIAL);
}
 
}
void Game::update()
{
/*
   if (!isRunning()) {
      splash();
      return;
   }
*/
   m_character->update();
   for(int i=0; i<m_gameObjects; i++)
      m_myGameObjects[i]->collide(m_character);

   for(int i=0; i<m_gameObjects; i++)
      m_myGameObjects[i]->update();

    //clear the screen
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set the clear color to white
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen

    // Display the current score
    char string[40];
    sprintf(string, "Score:\n%d", m_score);
    RenderString(0, m_height-20, GLUT_BITMAP_TIMES_ROMAN_24, string);

    m_character->display();
    for(int i=0; i<m_gameObjects; i++)
      m_myGameObjects[i]->display();
}
bool Game::isRunning() {
   return m_running;
}

void Game::setRun(bool b) {
   m_running = b;
}


void Game::init() {
    // Set up all the objects in the game that m_character can collide with in an array
    // called m_myGameObjects. m_gameObjects tells how many are defined.
    m_gameObjects = 0 ;
		m_myGameObjects[m_gameObjects] = new Character();
		m_gameObjects ++ ;
    m_character = dynamic_cast<Character*>(m_myGameObjects[0]);
    // m_myGameObjects[m_gameObjects] = new Paddle(m_width/2,5); // Paddle
    // m_gameObjects++;
    // m_myGameObjects[m_gameObjects] = new Wall(m_scorePanelWidth,0,m_scorePanelWidth,m_height, true ); // Left Wall
    // m_gameObjects++;
    // m_myGameObjects[m_gameObjects] = new Wall(m_width,0,m_width,m_height, false ); // Right Wall
    // m_gameObjects++;
    // m_myGameObjects[m_gameObjects] = new Wall(0,m_height,m_width,m_height, false ); // Top Wall
    // m_gameObjects++;
    m_myGameObjects[m_gameObjects] = new Wall(0,m_height/3,m_width,m_height/3, true ); // Floor
    m_gameObjects++;

    // Set the seed for the random variable generator just in case we need it.
    srandom(time(NULL));

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); // Use double buffering for smoother images
    glutInitWindowSize(m_width, m_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cockroach vs. Unicorns");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, m_width+m_margine, 0, m_height+m_margine);

    //m_splashTexture = ImageLoader::LoadTexture("images/cvuSplash.png");

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

    glutMainLoop(); // glutMainLoop enters the GLUT event processing loop. 
                    //This routine should be called at most once in a GLUT program. 
                    //Once called, this routine will never return. 
                    //It will call as necessary any callbacks that have been registered.
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    Game::getInstance().init();

}
