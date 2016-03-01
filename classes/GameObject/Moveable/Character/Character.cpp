#include "Character.h"

void Character::display()
{  
  if(m_display)
  {
    glColor3fv(colours[4]);
    rectangle(m_position_x, 
							m_position_y, 
							m_width, 
							m_width);
  }
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
void Character::dead()
{
  m_display = false;
  m_speed_x = 0;
  m_speed_y = 0;
}

void Character::reset(){
   m_display = true;
   m_speed_y = -1;
   m_speed = 1;
   m_position_x = 200;
   m_position_y = 250;
   m_width = 20;
   m_height = 20;
   m_jumping = true;
}

Character::Character() {
  m_display = true;
  m_speed_x = 0;
  m_speed_y = -1;
  m_speed = 1;
  m_position_x = 200;
  m_position_y = 250;
  m_width = 20;
  m_height = 20;
  m_jumping = true;
}
