#ifndef GAME_OF_LIFE_FUNC_H
#define GAME_OF_LIFE_FUNC_H

#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80

void input_field(int field[HEIGHT][WIDTH]);
void draw_field(int field[HEIGHT][WIDTH], int *generation_counter);
int neighbour_counter(int field[HEIGHT][WIDTH], int i, int j);
void get_next_generation(int field[HEIGHT][WIDTH], int *generation_counter);

#endif