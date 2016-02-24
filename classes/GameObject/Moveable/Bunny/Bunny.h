#ifndef BUNNY_H_
#define BUNNY_H_

#include "../Moveable.h"
#include "../Character/Character.h"

class Bunny : public Moveable {
   private:
   /*
   int m_position_x;
   int m_position_y;
   int m_width;
   */
   bool disp;
   /*
   int m_speed_x;
   int m_speed_y;
   int m_speed;
   */
   int m_health;
   public:
/*   
   // Get bunny size
   int getWidth() {return m_width;};
*/   
   void display();
   void update();
   void move();
   
   // Bunny hits character send character postion to check
   bool collide(Character *c);
   //  Player Character projectile send projectile to check
   //bool zapped(Lightning L);
   
   Bunny();
   
};

#endif /* BUNNY_H_ */
