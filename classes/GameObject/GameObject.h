#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <stdlib.h>
#include <math.h>
#include "../ImageLoader/ImageLoader.h"

class Character;

const GLfloat colours[7][3] = {
       { 1.0, 0.0, 0.0 }, // red
       { 1.0, 1.0, 0.0 }, // yellow
       { 0.0, 1.0, 0.0 }, // green
       { 0.0, 0.6, 0.6 }, // dark-green/blue
       { 1.0, 1.0, 1.0 }, // white
       { 1.0, 0.0, 1.0 }, // purple
       { 0.0, 0.0, 0.6 }  // dark-blue
};

const float Gravity = 0.5;

class GameObject {
  public:

  public:
   
    virtual void display () = 0;
    virtual void update () = 0;
    virtual bool collide (Character *c) { return false; }

};

#endif /* GAME_OBJEC_H_ */
