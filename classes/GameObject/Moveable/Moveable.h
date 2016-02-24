#ifndef MOVEABLE_H_
#define MOVEABLE_H_

#include "../GameObject.h"

class Moveable : public GameObject {
   public:
			// get positions 
      int get_left();
      int get_right();
      int get_top();
      int get_bottom();

			// get character size
      int get_width();
      int get_height();
			
			// get speeds
      int get_speed_down();
      int get_speed_up();
      int get_speed_left();
      int get_speed_right();

			// set positions
			void set_left(int v);
			void set_right(int v);
      void set_bottom(int y);
      void set_top(int y);

      virtual bool collide(Character *c);

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
