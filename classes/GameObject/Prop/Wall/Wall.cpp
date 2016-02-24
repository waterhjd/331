#include "Wall.h"

void Wall::display ()
{
   glColor3fv(colours[6]); // Set the color of the wall
   line(m_x1,m_y1, m_x2,m_y2);
}

bool Wall::collide (Character *c)
{
	// Vertical Wall
	if(m_x1 == m_x2) {
		if (c->get_left() < m_x1) {
			// c->bounceX();
			// m_ouch = 5;
		} else { 
			if (c->get_right() > m_x1) {
				// c->bounceX();
				// m_ouch = 5;
			}
		}
	}

	// Horizontal Wall
	else if(m_y1 == m_y2){

		// floor
		if (
				// the character will hit the wall from top after update
				(c->get_bottom() - c->get_speed_down() < m_y1)

				//the character is currently above the wall
				&& (c->get_top() > m_y1)

				//the character is above or below the wall
				&& (c->get_right() > m_x1)
				&& (c->get_left() < m_x2)
			 ) {


			c->stopJump();
			c->stopY();
			c->set_bottom(m_y1 + 1);
			return true;

		} 
		
		// ceiling
		else if (
				// character about to hit wall from bottom
				(c->get_top() + c->get_speed_up() > m_y1)

				// character currently below the wall
				&& (c->get_bottom() < m_y1)

				// character is above or below the wall
				&& (c->get_right() > m_x1)
				&& (c->get_left() < m_x2)
			 ) {

			std::cout << "ceiling\n";
			c->stopY();
			c->set_top(m_y1 - 1);
			return true;

		}
	}
	return false;
}

Wall::Wall(int x_1, int y_1, int x_2, int y_2) {
   m_x1=x_1;
   m_x2=x_2;
   m_y1=y_1;
   m_y2=y_2;
}
