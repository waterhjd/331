#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../Moveable.h"
#include <iostream>

using namespace std;

class Character: public Moveable {
   private:
    bool m_jumping;
   public:
    // void bounceX() {m_speed_x *= -1;};
    // void bounceY() {m_speed_y *= -1;};
		void stopY() {m_speed_y = 0;};
    void stop() {m_speed_x = 0;};
		void jump();
		void right();
		void left();
		void stopJump() {m_jumping = false;};
    void display();
    // void update();
    bool collide(Character c) {return false;};
    Character();
};

#endif /* CHARACTER_H_ */
