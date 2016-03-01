#include <GL/freeglut.h>

#include "game/Game.h"

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    Game::getInstance().init();
}
