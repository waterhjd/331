#ifndef BORDER_H_
#define BORDER_H_

#include "../Prop.h"
#include "../../Moveable/Character/Character.h"

class Border: public Prop {
   protected:
      int m_x1,m_y1, m_x2, m_y2;
      
   public:
    void display () {};
    void update (int x_offset);
    void update () {};
    bool collide (Character *c);
    Border(int x_1, int y_1, int x_2, int y_2);
    Border();
};

#endif /* BORDER_H_ */
