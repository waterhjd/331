#ifndef WALL_H_
#define WALL_H_

#include "../Prop.h"
#include "../../Moveable/Character/Character.h"

class Wall: public Prop {
   protected:
      int m_x1,m_y1, m_x2, m_y2;
      bool m_minwall;
      
   public:
    void display ();
    void update () {};
    bool collide (Character *c);
    Wall(int x_1, int y_1, int x_2, int y_2, bool min_wall);
    Wall() {};
};

#endif /* WALL_H_ */
