#include "Character.h"

void Character::display()
{  
    glColor3fv(colours[4]);
    rectangle(m_position_x, 
							m_position_y, 
							m_width, 
							m_width);
}


void Character::jump() {
	if (!m_jumping) {
		m_speed_y = 20;
		m_jumping = true;
	}
}

void Character::right() {
	m_position_x += 2;	
  m_speed_x = 2;
}

void Character::left() {
	m_position_x -= 2;	
  m_speed_x = -2;
}

Character::Character() {
  m_speed_x = 0;
  m_speed_y = -1;
  m_speed = 1;
  m_position_x = 200;
  m_position_y = 250;
  m_width = 20;
	m_height = 20;
  m_jumping = true;
}
