#ifndef CAR_H_
#define CAR_H_

#include <GL/freeglut.h>

class Car {  
   private:
    int m_x;  
    int m_y; 
    float m_direction;
    float m_speed;

    int m_xangle;
    int m_yangle; 

    GLuint m_carTexture;   

   public:
    void left ();
    void right ();
    void display ();
    void displayWireFrame ();
    void displaySolidCube ();
    void displayTexture ();
    void update ();
    void init();
    Car(int x = 260, int y = 170);
};

#endif /* CAR_H_ */
