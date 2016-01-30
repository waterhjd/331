#include "Character.h"

void Character::display()
{  
    //Draw the bounding reactange fo the ball
    glColor3fv(colours[2]);
    rectangle(m_x, m_y, m_r, m_r);
    // Draw the ball
    glColor3fv(colours[0]); // Set the color of the ball
    circle(m_x, m_y, m_r, m_r);
}

void Character::update()
{ 
    m_x += m_ball_speed_x * m_ball_speed;
    m_y += m_ball_speed_y * m_ball_speed;
}

Character::Character()
{
   m_ball_speed_x = 0;
   m_ball_speed_y = 0;
   m_ball_speed = 1;
   m_x=200;
   m_y = 150;
   m_r=20;
}
