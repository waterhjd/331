#include "Character.h"
#include "../../../ImageLoader/ImageLoader.h"

void Character::display()
{  
   /*
   m_height = m_text_height[m_currImg];
   m_width = m_text_width[m_currImg];
   
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   
   glBindTexture (GL_TEXTURE_2D, m_textures[m_currImg]);
*/
   glColor3fv(colours[4]); 
   ImageLoader::rectangle(m_position_x, 
                          m_position_y, 
                          m_width, 
                          m_height);
   //glDisable(GL_TEXTURE_2D);

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
  //m_textures[0] = ImageLoader::LoadTexture("images/cockroach_right.bmp", m_text_width[0], m_text_height[0]);
  m_currImg = 0;
  m_speed_x = 0;
  m_speed_y = -1;
  m_speed = 1;
  m_position_x = 200;
  m_position_y = 250;
  m_width = 20;
	m_height = 20;
  m_jumping = true;
}
