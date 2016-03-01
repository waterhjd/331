#include "Character.h"


const char *m_charLeftFile = "./images/cockroach_left.bmp";
const char *m_charRightFile = "./images/cockroach_right.bmp";

void Character::update() {
   Moveable::update();
   if (m_position_y < 0) dead();
}


void Character::display()
{  
  if(m_display)
  {
   glEnable(GL_TEXTURE_2D);
   
   // Enable alpha layer transparency
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   // End alpha

   glBindTexture (GL_TEXTURE_2D, m_charRight);
   ImageLoader::rectangleFile(m_position_x,m_position_y, m_width, m_height);

   glDisable(GL_TEXTURE_2D);
   glFlush();
/*
    glColor3fv(colours[4]);
    ImageLoader::rectangle(m_position_x, 
							m_position_y, 
							m_width, 
							m_width);
*/
   }
}


void Character::jump() {
	if (m_jumps < 2) {
   m_jumps++;
		m_speed_y = 10;
		m_jumping = true;
	}
}
void Character::stopX() {
   m_speed_x = 0;
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
  m_dead = true;
}
void Character::reset(){
   m_display = true;
   m_jumps = 0;
   m_currImg = 1;
   m_dead = false;
   m_speed_x = 0;
   m_speed_y = -1;
   m_speed = 1;
   m_position_x = 200;
   m_position_y = 450;
   m_width = 20;
   m_height = 20;
   m_jumping = true;
}
void Character::init() {
   m_charLeft = ImageLoader::LoadTexture(m_charLeftFile, m_width, m_height);
   m_charRight = ImageLoader::LoadTexture(m_charRightFile, m_width, m_height);

}
Character::Character() {
   m_currImg = 1;
   m_display = true;
   m_jumps = 0;
   m_dead = false;
   m_speed_x = 0;
   m_speed_y = -1;
   m_speed = 1;
   m_position_x = 200;
   m_position_y = 450;
   m_width = 20;
   m_height = 20;
   m_jumping = true;
   

}
