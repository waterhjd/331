#include "Border.h"

// void Border::display ()
// {
//    glColor3fv(colours[6]); // Set the color of the wall
//    line(m_x1,m_y1, m_x2,m_y2);
// }

void Border::update (int x_offset) {
	m_x1 = x_offset;
	m_x2 = x_offset;
}

bool Border::collide (Character *c)
{
	// Vertical Border
	if(m_x1 == m_x2) {
		if (c->get_left() < m_x1) {
			c->stopX();
			c->set_left(m_x1);
			return true;
		}
	}

	return false;
}

Border::Border()
{
  m_x1=0;
  m_x2=0;
  m_y1=0;
  m_y2=0;
}

Border::Border(int x1, int x2, int y1, int y2)
{
  m_x1 = x1;
  m_x2 = x2;
  m_y1 = y1;
  m_y2 = y2;
}
