CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: game_of_life

game_of_life: game_of_life_func.o game_of_life.c
	$(CC) $(CFLAGS) -lncurses game_of_life.c game_of_life_func.o -o game_of_life

game_of_life_func.o: game_of_life_func.h game_of_life_func.c
	$(CC) $(CFLAGS) -c game_of_life_func.c

clean:
	rm -rf *.o
	clang-format -i *.c *.h

rebuild:
	make clean
	make