#include "Moveable.h"

void Moveable::update() {
	m_speed_y -= Gravity;
	m_position_y += m_speed_y * m_speed;
	m_position_x += m_speed_x * m_speed;
}

void Moveable::display() {
}

int Moveable::get_left() {
	return m_position_x;
}

int Moveable::get_right() {
	return m_position_x + m_width;
}

int Moveable::get_top() {
	return m_position_y + m_height;
}

int Moveable::get_bottom() {
	return m_position_y;
}

int Moveable::get_width() {
	return m_width;
}

int Moveable::get_height() {
	return m_height;
}

int Moveable::get_speed_down() {
	return - m_speed_y;
}

int Moveable::get_speed_up() {
	return m_speed_y;
}

int Moveable::get_speed_left() {
	return - m_speed_x;
}

int Moveable::get_speed_right() {
	return m_speed_x;
}

void Moveable::set_left(int v) {
	m_position_x = v;
}

void Moveable::set_right(int v) {
	m_position_x = v - m_width;
}

void Moveable::set_bottom(int y) {
	m_position_y = y;
}

void Moveable::set_top(int y) {
	m_position_y = y - m_height;
}

bool Moveable::collide(Character *c) { 
	return false;
}
