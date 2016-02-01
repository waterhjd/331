CC = g++
LDLIBS = -lglut -lGL -lGLU -lX11 -lm
OBJ = Game.cpp \
      Character.cpp \
      Wall.cpp \
      ImageLoader.cpp

All: $(OBJ)
	$(CC) $(OBJ)  $(LDLIBS) -o game

clean:
	rm -f game
