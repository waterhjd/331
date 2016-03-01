#ifndef SCROLLER_H_
#define SCROLLER_H_

#include <GL/glut.h> 
#include "../GameObject/Moveable/Character/Character.h"
#include "../GameObject/Prop/Border/Border.h"

class Scroller {
	private:
		Character *m_character;
		Border *m_left_border;

		/** 
		 * m_x_distance tracks how for along the x axis
		 * the player has travelled.
		 * In terms of the camera view, it is always
		 * at the left edge of the window
		 */
		int m_x_distance;
		int m_window_width;
	public:
		void update();
		Scroller(Character *c, int window_width);
};

#endif /* SCROLLER_H_ */
