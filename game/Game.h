/*******************************
 * This is the main game board.
 * It is implemented as a Singleton: That measn there can only be one instance.
 *******************************/
#ifndef GAME_H_
#define GAME_H_

#include "../classes/GameObject/Moveable/Character/Character.h"
#include "../classes/Scroller/Scroller.h"

class GameObject;
class Character;

#define MAX_OBJECTS 50

class Game {
// Required portions for making this a Singleton.
    public:
        // Insead of a constructor, use this static method to create an instance
        // (or used the already created instance) of Game
        static Game& getInstance()
        {
            static Game    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }
    private:
        // Make al the constructors private. If you want an instance, use the 
        // getInstance() method above
        Game() {
           m_margine = 0;
           m_width = 600;
           m_height = 600;
        }; // Default Constructor (the {} brackets) are needed here, even if it is empty.
        Game(Game const&);           // Don't Implement
        void operator=(Game const&); // Don't implement

// Now that we are  a Singleton, define the rest fo the class as usual.
   private:
      const static int c_interval = 1000 / 60; // 60 frames per second

      // window size 
      int m_width;
      int m_height;
      int m_margine;
      int m_scorePanelWidth;
			int m_x_distance;
      GLuint m_splashTexture;

      // Items in the game
      Character m_myCharacter;
			Character *m_character;
			Scroller *m_scroller;
      int m_gameObjects;
      GameObject *m_myGameObjects[MAX_OBJECTS];
      int m_score;
      GLint m_windowID;
      bool m_running;
      bool m_gameOver;
   public:
      GLint getWinID() {return m_windowID;};
      // Functions for GL. key handles keyboard input. Run is the comuting loop
      // Run calls update
      static void key(unsigned char key, int x, int y);
      static void run();
      static void idle();
      static void timer(int id);
      void update();


      void RenderString(float x, float y, void *font, const char* string);
      void updateScore(int addMe) {m_score += addMe;};

      // GameObject *character() {return m_myGameObjects[0];};
      GameObject *character() {return m_character;};

      void init();
      void splash();
      void gameOver();
      bool isGameOver() {return m_gameOver;};
      void setGameOver(bool g) {m_gameOver = g;};
      void reset();
      bool isRunning() {return m_running;};
      void setRun(bool b) {m_running = b;};
      GLfloat frand();
};

#endif /* GAME_H_ */
