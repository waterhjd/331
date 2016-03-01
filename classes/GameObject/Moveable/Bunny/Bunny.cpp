#include "Bunny.h"
#include <iostream>

using namespace std;

void Bunny::display() {
   if(m_display)
   {
      glColor3fv(colours[2]);
      ImageLoader::rectangle(m_position_x,
                 m_position_y,
                 m_width,
                 m_width);
   }
}

void Bunny::update() {
   // Walk left perpetually
   m_position_x -= m_speed_x;
   
}

bool Bunny::collide(Character* c)
{
  int bunnyLeft = m_position_x;
  int bunnyRight = m_position_x + m_width;
  int bunnyBot = m_position_y;
  int bunnyTop = m_position_y + m_width;

  if(m_display)
  {
      if((bunnyRight> c->get_left())&&(bunnyLeft < c->get_right())&&((((c->get_bottom() >= bunnyTop-10)&&(c->get_bottom() <= bunnyTop+20) ))))
      {	
         this->killed();
         c->stopJump();
         c->stopX();
         
         return true;
      }
     
      
      if((bunnyRight > c->get_left())&&(bunnyLeft < c->get_right())&&(bunnyTop > c->get_bottom())) 
      {
         c->dead();
      }
     return true;
  }
}
int Bunny::get_left()
{
   return (m_position_x);
}
int Bunny::get_right()
{
   return (m_position_x + m_width);
}
int Bunny::get_bot()
{
   return (m_position_y);
}
int Bunny::get_top()
{
   return (m_position_y + m_width);
}

void Bunny::killed()
{
   m_display = false;
}

Bunny::Bunny(int height)
{
   m_display = true;
   m_speed_x = 1;
   m_speed_y = -1;
   m_speed = 1;
   m_position_x = 500;
   m_position_y = height; 
   m_width = 40;
}
