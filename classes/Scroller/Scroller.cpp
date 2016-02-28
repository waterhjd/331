#include "Scroller.h"

void Scroller::update() {
	int character_pos_minus_center;
	int window_center = m_window_width / 2;

	// make sure character doesn't move past left border
	m_left_border->collide(m_character);

	// calculate m_x_distance so that it only increases
	// when character tries to move into right half of screen
	character_pos_minus_center = m_character->get_left() - window_center;
	if (m_x_distance < character_pos_minus_center) {
		m_x_distance = character_pos_minus_center;
	}

	// keep left border updated as the camera moves right
	m_left_border->update(m_x_distance);


	// set camera to be centered at m_x_distance
	glTranslatef(- m_x_distance, 0.0, 0.0);
}

Scroller::Scroller(Character *c, int window_width) {
	m_character = c;
	m_left_border = new Border(0,0,0,0); 
	m_x_distance = 0;	
	m_window_width = window_width;
}
