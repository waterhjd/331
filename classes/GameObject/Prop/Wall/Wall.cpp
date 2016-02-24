#include "Wall.h"

void Wall::display ()
{
   glColor3fv(colours[6]); // Set the color of the wall
   line(m_x1,m_y1, m_x2,m_y2);
}

bool Wall::collide (Character *c)
{
   // Vertical Wall
   // if(m_x1 == m_x2)
   // {
   //    if(m_minwall)
   //    {
   //       if (c->getX() < m_x1) 
   //       {
   //           c->bounceX();
   //           m_ouch = 5;
   //       }
   //    }
   //    else
   //    { 
   //       if (c->getX() + c->get_width() > m_x1)
   //       {
   //           c->bounceX();
   //           m_ouch = 5;
   //       }
   //    }
   // }

   // Horizontal Wall
   if(m_y1 == m_y2)
   {
      if(m_minwall) //this is the floor
      {
         if (c->getY()<= m_y1+c->get_width())
         {
						 c->stopJump();
						 c->stopY();
                   c->setY(m_y1+5);
                   return true;
         }
      }
      else 
      {
         if (c->getY() + c->get_width() > m_y1)
         {
             c->stopY();
             return true;
         }
      }
   }
   return false;
}

Wall::Wall(int x_1, int y_1, int x_2, int y_2, bool min_wall)
{
   m_x1=x_1;
   m_x2=x_2;
   m_y1=y_1;
   m_y2=y_2;
   m_minwall = min_wall;
}
