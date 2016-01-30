#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "GameObject.h"

class Character: public GameObject {
   private:
      int m_x,m_y,m_r;
      int m_ball_speed_x;
      int m_ball_speed_y;
      int m_ball_speed;      
   public:
    int getX() {return m_x;};
    int getY() {return m_y;};
    int getR() {return m_r;};
    void bounceX() {m_ball_speed_x *= -1;};
    void bounceY() {m_ball_speed_y *= -1;};
    void display ();
    void update ();
    bool collide (Character b) {return false;};
    Character();
};

#endif /* CHARACTER_H_ */
