#ifndef BUNNY_H_
#define BUNNY_H_

#include "../bunny.h"

class bunny : public bunny {
   private:
   int m_position_x;
   int m_position_y;
   int m_width;
   
   int m_speed_x;
   int m_speed_y;
   int m_speed;
   
   int m_health;
   public:
   
   // Get Bunny Position
   int getX() {return m_position_x;};
   
   //Get Bunny Vertical position
   int getY() {return m_position_y;};
   
   // Get bunny size
   int getWidth() {return m_width};
   
   void display();
   void update();
   void move();
   
   // Bunny hits character send character postion to check
   bool collide(Character c);
   //  Player Character projectile send projectile to check
   bool zapped(Lightning L);
   
   bunny();
   
};

#endif /* BUNNY_H_ */
