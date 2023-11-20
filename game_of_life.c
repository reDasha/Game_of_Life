#include "game_of_life_func.h"

int main() {
  const int max_tick_ms = 500000;
  int tick_ms = 70000;
  int field[HEIGHT][WIDTH] = {0};
  int generation_counter = 0;

  input_field(field);
  if (!freopen("/dev/tty", "r", stdin))
    stdin = fopen("/dev/tty", "r");

  initscr();
  start_color();
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  nodelay(stdscr, TRUE);
  curs_set(0);
  noecho();
  draw_field(field, &generation_counter);

  while (1) {
    int key = getch();
    if (key == 'a' && tick_ms < max_tick_ms) {
      tick_ms *= 2;
    }
    if (key == 'd') {
      tick_ms /= 2;
    }
    if (key == 'q') {
      break;
    }
    get_next_generation(field, &generation_counter);
    draw_field(field, &generation_counter);
    usleep(tick_ms);
  }
  endwin();
  return 0;
}