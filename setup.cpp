#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <random>
#include <time.h>
#include"func1.h"
#include"func2.h"
#include"define.h"

#define WINDOW_X 80
#define WINDOW_Y 34
#define MAX_NUM 128

void init_window1()
{
  curs_set(0); 
  int w_x = 0, w_y = 0;
  char err[] = "You must set window size as more than 100 x 25";
  char ok[] = "Press Any key";
  getmaxyx(stdscr, w_y, w_x);
  while (w_x <= 105 || w_y <= 25)
  {
    mvprintw(w_y / 2, w_x / 2 - (strlen(err) / 2), "%s", err);
    refresh();
    getmaxyx(stdscr, w_y, w_x);
    clear();
  }
  mvprintw(w_y / 2, w_x / 2 - (strlen(ok) / 2), "%s", ok);
  refresh();
  getch();
}
void init_window2()
{
  curs_set(0); 
  int w_x = 0, w_y = 0;
  char err[] = "You must set window size as  80 x 34";
  char ok[] = "Press Any key";
  getmaxyx(stdscr, w_y, w_x);
  while (w_x != WINDOW_X || w_y != WINDOW_Y)
  {
    mvprintw(w_y / 2, w_x / 2 - (strlen(err) / 2), "%s", err);
    refresh();
    getmaxyx(stdscr, w_y, w_x);
    clear();
  }
  refresh();
  getch();
  clear();
}
void draw_name()
{
  curs_set(0); 
  int w_x = 0, w_y = 0;
  getmaxyx(stdscr, w_y, w_x);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  char t1[7][MAX_NUM] = {" _______  ___   _____    _______  _______  _____   _______  _______  _______    _       _   ",
                         "|       ||   | |     |  |       ||   _   ||     | |       ||       ||       | _| |_   _| |_ ",
                         "|_     _||   | |     |  |_     _||  |_|  ||     | |_     _||   _   ||    ___||_   _| |_   _|",
                         "  |   |  |   | |   __|    |   |  |       ||   __|   |   |  |  | |  ||   |___   |_|     |_|  ",
                         "  |   |  |   | |  |       |   |  |       ||  |      |   |  |  |_|  ||    ___|               ",
                         "  |   |  |   | |  |__     |   |  |   _   ||  |__    |   |  |       ||   |___                ",
                         "  |___|  |___| |_____|    |___|  |__| |__||_____|   |___|  |_______||_______|               "};
  char t2[3][MAX_NUM] = {"1.START",
                         "2.HELP",
                         "0.EXIT"};
  int j = 0;
  clear();
  for (int i = 0; i < 7; i++)
  {
    attrset(COLOR_PAIR(1));
    mvaddstr(w_y / 3.5 + j, w_x / 2 - (strlen(t1[i]) / 2), t1[i]);
    j++;
  }
  j += 5;
  for (int i = 0; i < 3; i++)
  {
    attrset(COLOR_PAIR(2));
    mvaddstr(w_y / 3.5 + j, w_x / 2 - (strlen(t2[i]) / 2), t2[i]);
    j++;
  }
  refresh();
}
void help()
{
  curs_set(0); 
  clear();
  draw_name();
  FILE *fp;
  char fname[] = "help.txt";
  char err[] = "File not open!";
  int chr;

  fp = fopen(fname, "r");
  if (fp == NULL)
  {
    mvprintw(WINDOW_Y / 2.5, WINDOW_X / 2 - ((strlen(err) + strlen(fname)) / 2), "%s %s", fname, err);
  }
  while ((chr = fgetc(fp)) != EOF)
  {
    putchar(chr);
  }
  fclose(fp);
}
void draw_board()
{
  curs_set(0); 
  int x, y;
  start_color();
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  getmaxyx(stdscr, y, x);
  box(stdscr, ACS_VLINE, ACS_HLINE);
  x -= 16;
  mvhline(y / 3, 0, ACS_HLINE, x + 16);
  mvhline(y / 3 * 2, 0, ACS_HLINE, x + 16);
  mvvline(0, x / 3, ACS_VLINE, y);
  mvvline(0, x / 3 * 2, ACS_VLINE, y);
  mvvline(0, x / 3 * 3, ACS_VLINE, y);

  attrset(COLOR_PAIR(6));
  mvaddstr(2, 68, "Player1");
  attrset(COLOR_PAIR(2));
  mvaddstr(13, 68, "Player2");
  mvaddch(1, 1, '1');
  mvaddch(12, 1, '4');
  mvaddch(23, 1, '7');
  mvaddch(1, 22, '2');
  mvaddch(12, 22, '5');
  mvaddch(23, 22, '8');
  mvaddch(1, 43, '3');
  mvaddch(12, 43, '6');
  mvaddch(23, 43, '9');
  print_itemNum();
  refresh();
}

