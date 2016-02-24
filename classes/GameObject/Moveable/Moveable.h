#ifndef MOVEABLE_H_
#define MOVEABLE_H_

#include "../GameObject.h"

class Moveable : public GameObject {
   public:
      int getX() {return m_position_x;};
      int getY() {return m_position_y;};
      int getR() {return m_width;};
			void set_left(int v) {m_position_x = v;}
			void set_right(int v) {m_position_x = v - m_width;}
      void setY(int y) {m_position_y=y;};
      virtual bool collide (Character *c) { return false; }


   private:

   protected:
      int m_position_x;
      int m_position_y;
      int m_speed_x;
      int m_speed_y;
      int m_speed;
      int m_width;
      int m_height;


};

#endif /* MOVEABLE_H_ */
