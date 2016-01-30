#include "Character.h"

void Character::display()
{  
    //Draw the bounding reactange fo the ball
    glColor3fv(colours[2]);
    rectangle(m_position_x, 
							m_position_y, 
							m_width, 
							m_width);
    // Draw the ball
    glColor3fv(colours[0]); // Set the color of the ball
    // circle(m_x, m_y, m_r, m_r);
}

void Character::update()
{ 
    // m_x += m_ball_speed_x * m_ball_speed;
    m_position_y += m_speed_y * m_speed;
}

Character::Character()
{
   m_speed_x = 0;
   m_speed_y = -1;
   m_speed = 1;
   m_position_x = 200;
   m_position_y = 150;
   m_width = 20;
}
