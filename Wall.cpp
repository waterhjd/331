#include "Wall.h"

void Wall::display ()
{
   m_ouch --;
   if(m_ouch<0) m_ouch = 0;
   glColor3fv(colours[m_ouch]); // Set the color of the wall
   line(m_x1,m_y1, m_x2,m_y2);
}

bool Wall::collide (Character *b)
{
   // Vertical Wall
   if(m_x1 == m_x2)
   {
      if(m_minwall)
      {
         if (b->getX() < m_x1) 
         {
             b->bounceX();
             m_ouch = 5;
         }
      }
      else
      { 
         if (b->getX() + b->getR() > m_x1)
         {
             b->bounceX();
             m_ouch = 5;
         }
      }
   }

   // Horizontal Wall
   if(m_y1 == m_y2)
   {
      if(m_minwall)
      {
         if (b->getY() < m_y1)
         {
             b->bounceY();
             m_ouch = 5;
         }
      }
      else
      {
         if (b->getY() + b->getR() > m_y1)
         {
             b->bounceY();
             m_ouch = 5;
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
   m_ouch = 0;
}
