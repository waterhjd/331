#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "GameObject.h"

class Character: public GameObject {
   private:
      int m_position_x;
			int m_position_y;
			int m_width;
      int m_speed_x;
      int m_speed_y;
      int m_speed;      
   public:
    int getX() {return m_position_x;};
    int getY() {return m_position_y;};
    int getR() {return m_width;};
    void bounceX() {m_speed_x *= -1;};
    void bounceY() {m_speed_y *= -1;};
    void display ();
    void update ();
    bool collide (Character c) {return false;};
    Character();
};

#endif /* CHARACTER_H_ */
