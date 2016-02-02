#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Moveable.h"
#include <iostream>

using namespace std;

class Character: public Moveable {
   private:
      int m_position_x;
			int m_position_y;
			int m_width;
      int m_speed_x;
      int m_speed_y;
      int m_speed;      
			int m_jumping;
   public:
    int getX() {return m_position_x;};
    int getY() {return m_position_y;};
    int getR() {return m_width;};
    // void bounceX() {m_speed_x *= -1;};
    // void bounceY() {m_speed_y *= -1;};
		void stopY() {m_speed_y = 0;};
		void jump();
		void right();
		void left();
		void stopJump() {m_jumping = false;};
    void display();
    void update();
    bool collide(Character c) {return false;};
    Character();
};

#endif /* CHARACTER_H_ */
