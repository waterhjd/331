CC = g++
LDLIBS = -lglut -lGL -lGLU -lX11 -lm  
OBJ = Game.cpp \
      Car.cpp \
      ImageLoader.cpp

All: $(OBJ)
	$(CC) $(OBJ)  $(LDLIBS) -o game
