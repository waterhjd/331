CC = g++
LDLIBS = -lglut -lGL -lGLU -lX11 -lm
OBJ = game/Game.cpp \
      classes/GameObject/Moveable/Character/Character.cpp \
      classes/GameObject/Moveable/Bunny/Bunny.cpp \
      classes/GameObject/Prop/Wall/Wall.cpp \
      classes/ImageLoader/ImageLoader.cpp

All: $(OBJ)
	$(CC) $(OBJ)  $(LDLIBS) -o cvu

clean:
	rm -f cvu
