EXEC = game
OBJ  = main.o sheep.o wolf.o map.o
CC = g++

all: $(EXEC)

game: $(OBJ)
		$(CC) $(LDFLAGS) -o $@ $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system -ltinyxml -lz -ltmxparser -std=c++11

%.o: %.cpp
		$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
