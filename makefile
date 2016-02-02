CC = g++
LDLIBS = -lglut -lGL -lGLU -lX11 -lm
OBJ = game/Game.cpp \
      classes/GameObject/Character/Character.cpp \
      classes/ImageLoader/ImageLoader.cpp \
      classes/GameObject/Wall/Wall.cpp

All: $(OBJ)
	$(CC) $(OBJ)  $(LDLIBS) -o cvu

clean:
	rm -f cvu
