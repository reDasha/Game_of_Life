#include "game_of_life_func.h"

void input_field(int field[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      scanf("%d", &field[i][j]);
    }
  }
}

void draw_field(int field[HEIGHT][WIDTH], int *generation_counter) {
  clear();
  attron(COLOR_PAIR(1));
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      if (field[i][j] == 1) {
        printw("0");
      } else {
        printw(" ");
      }
    }
    printw("\n");
  }
  attroff(COLOR_PAIR(1));
  printw("%s GENERATION #%d", " ", *generation_counter);
  refresh();
}

int neighbour_counter(int field[HEIGHT][WIDTH], int i, int j) {
  int neighbours = 0;
  neighbours += field[(i + HEIGHT - 1) % HEIGHT][(j + WIDTH - 1) % WIDTH];
  neighbours += field[(i + HEIGHT - 1) % HEIGHT][(j + WIDTH + 1) % WIDTH];
  neighbours += field[(i + HEIGHT - 1) % HEIGHT][j];
  neighbours += field[(i + HEIGHT + 1) % HEIGHT][j];
  neighbours += field[(i + HEIGHT + 1) % HEIGHT][(j + WIDTH - 1) % WIDTH];
  neighbours += field[(i + HEIGHT + 1) % HEIGHT][(j + WIDTH + 1) % WIDTH];
  neighbours += field[i][(j + WIDTH + 1) % WIDTH];
  neighbours += field[i][(j + WIDTH - 1) % WIDTH];
  return neighbours;
}

void get_next_generation(int field[HEIGHT][WIDTH], int *generation_counter) {
  int generation[HEIGHT][WIDTH] = {0};

  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      int neighbours = neighbour_counter(field, i, j);
      if (neighbours == 3 || (field[i][j] == 1 && neighbours == 2)) {
        generation[i][j] = 1;
      }
      neighbours = 0;
    }
  }
  for (int i = 0; i < HEIGHT; ++i) {
    for (int j = 0; j < WIDTH; ++j) {
      field[i][j] = generation[i][j];
    }
  }
  ++*generation_counter;
}