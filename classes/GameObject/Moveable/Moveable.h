#ifndef MOVEABLE_H_
#define MOVEABLE_H_

#include "../GameObject.h"

class Moveable : public GameObject {
   public:
      int get_left() {return m_position_x;};
      int get_right() {return m_position_x + m_width;};
      int get_top() {return m_position_y + m_height;};
      int get_bottom() {return m_position_y;};
      int get_width() {return m_width;};
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
