#include "Scroller.h"

void Scroller::update() {
	m_left_border->collide(m_character);
	if (m_x_distance < m_character->get_left() - (m_window_width / 2)) {
		m_x_distance = m_character->get_left() - (m_window_width / 2);
	}
	m_left_border->update(m_x_distance);
	glTranslatef(- m_x_distance, 0.0, 0.0);
}

Scroller::Scroller(Character *c, int window_width) {
	m_character = c;
	m_left_border = new Border(0,0,0,0); 
	m_x_distance = 0;	
	m_window_width = window_width;
}
