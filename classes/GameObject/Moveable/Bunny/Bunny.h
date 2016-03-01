#ifndef BUNNY_H_
#define BUNNY_H_

#include "../Moveable.h"
#include "../Character/Character.h"
class Bunny : public Moveable {
   private:
   int m_position_x;
   int m_position_y;
   int m_width;
   
   int m_speed_x;
   int m_speed_y;
   int m_speed;
   
   bool m_display;
   int m_health;
   public:
   
   int get_left();
   int get_right();
   int get_bot();
   int get_top();
   
   // Get bunny size
   int getWidth() {return m_width;};
   
   void display();
   void update();
   void move();
   
   // Bunny hits character send character postion to check
   bool collide(Character* c);
   //  Player Character projectile send projectile to check
   void killed();
   
   Bunny(){};
   Bunny(int height);   
};

#endif /* BUNNY_H_ */
