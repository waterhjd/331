#include "Character.h"

void Character::display()
{  
    glColor3fv(colours[4]);
    rectangle(m_position_x, 
							m_position_y, 
							m_width, 
							m_width);
}

void Character::update()
{ 
    // m_x += m_ball_speed_x * m_ball_speed;
		// m_position_y += m_speed_y * m_speed ;
		// if (m_speed_y * m_speed > Gravity) {
		// 	m_position_y += m_speed_y * m_speed - Gravity ;
		// }
		// else if (m_{
		// 	m_speed_y = 0;
		// 	m_position_y += m_speed_y * m_speed;
		// }
		// if (m_jumping) {
			m_speed_y -= Gravity;
			m_position_y += m_speed_y * m_speed;
		// }
    m_position_x += m_speed_x * m_speed;


		// if (m_speed_y != 0)
		// 	m_speed_y -= Gravity;
		// m_position_y += m_speed_y * m_speed ;
		
}

void Character::jump()
{
	if (!m_jumping) {
		m_speed_y = 20;
		m_jumping = true;
	}
	// if (m_speed_y == 0) {
	// 	m_speed_y = 3 ;
	// }
}

void Character::right()
{
	m_position_x += 1;	
   m_speed_x = 1;
}

void Character::left()
{
	m_position_x -= 1;	
   m_speed_x = -1;
}

Character::Character()
{
   m_speed_x = 0;
   m_speed_y = -1;
   m_speed = 1;
   m_position_x = 200;
   m_position_y = 250;
   m_width = 20;
   m_jumping = true;
}
