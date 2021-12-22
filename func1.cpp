#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <random>
#include <time.h>
#include"func2.h"
#include"setup.h"
#include"define.h"

#define BD_ORG_X 1
#define BD_ORG_Y 1

void print_itemNum()
{
  mvprintw(4, 68, "Large:%d", p1_large);
  mvprintw(6, 68, "Medium:%d", p1_medium);
  mvprintw(8, 68, "Small:%d", p1_small);
  mvprintw(15, 68, "Large:%d", p2_large);
  mvprintw(17, 68, "Medium:%d", p2_medium);
  mvprintw(19, 68, "Small:%d", p2_small);
}
void decrease_item(int type)
{
  if (type == 0)
  {
    if (turn == true)
    {
      p1_small--;
    }
    else
    {
      p2_small--;
    }
  }
  else if (type == 1)
  {
    if (turn == true)
    {
      p1_medium--;
    }
    else
    {
      p2_medium--;
    }
  }
  else if (type == 2)
  {
    if (turn == true)
    {
      p1_large -= 1;
    }
    else
    {
      p2_large -= 1;
    }
  }
}
void spawn_block(int m_x, int m_y, bool turn)
{
  start_color();
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLUE);
  init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
  if (turn != true)
  {
    attrset(COLOR_PAIR(3));
  }
  else
  {
    attrset(COLOR_PAIR(4));
  }
  for (int i = 0; i < IT_HEIGHT; ++i)
  {
    int y = g_y + i;
    for (int j = 0; j < IT_WIDTH; ++j)
    {
      int x = g_x + j;
      if (item_s[j][i] == 1)
      {
        move(BD_ORG_Y + y + m_y, BD_ORG_X + x + m_x);
        addch('A');
      }
    }
  }
  attrset(COLOR_PAIR(2));
}
int set_form(int type)
{
  for (int y = 0; y < IT_HEIGHT; ++y)
  {
    for (int x = 0; x < IT_WIDTH; ++x)
    {
      item_s[x][y] = items[type][y][x];
    }
  }
  return type;
}
void draw_item(int type)
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  mvaddstr(25, 66, "SELECT GRID");
  mvaddstr(26, 66, "   1 ~ 9   ");
  noecho();
  int key = getch();
  if (key == '1')
  {
    if (type > grid[1][0][0])
    {
      spawn_block(1, 1, turn);
      if (turn == true)
      {
        grid[0][0][0] = 1;
      }
      else
      {
        grid[0][0][0] = 0;
      }
      grid[1][0][0] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
  }
  else if (key == '2')
  {
    if (type > grid[1][0][1])
    {
      spawn_block(22, 1, turn);
      if (turn == true)
      {
        grid[0][0][1] = 1;
      }
      else
      {
        grid[0][0][1] = 0;
      }
      grid[1][0][1] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
  }
  else if (key == '3')
  {
    if (type > grid[1][0][2])
    {
      spawn_block(43, 1, turn);
      if (turn == true)
      {
        grid[0][0][2] = 1;
      }
      else
      {
        grid[0][0][2] = 0;
      }
      grid[1][0][2] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
  }
  else if (key == '4')
  {
    if (type > grid[1][1][0])
    {
      spawn_block(1, 12, turn);
      if (turn == true)
      {
        grid[0][1][0] = 1;
      }
      else
      {
        grid[0][1][0] = 0;
      }
      grid[1][1][0] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
  }
  else if (key == '5')
  {
    if (type > grid[1][1][1])
    {
      spawn_block(22, 12, turn);
      if (turn == true)
      {
        grid[0][1][1] = 1;
      }
      else
      {
        grid[0][1][1] = 0;
      }
      grid[1][1][1] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
  }
  else if (key == '6')
  {
    if (type > grid[1][1][2])
    {
      spawn_block(43, 12, turn);
      if (turn == true)
      {
        grid[0][1][2] = 1;
      }
      else
      {
        grid[0][1][2] = 0;
      }
      grid[1][1][2] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
  }
  else if (key == '7')
  {
    if (type > grid[1][2][0])
    {
      spawn_block(1, 23, turn);
      if (turn == true)
      {
        grid[0][2][0] = 1;
      }
      else
      {
        grid[0][2][0] = 0;
      }
      grid[1][2][0] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
  }
  else if (key == '8')
  {
    if (type > grid[1][2][1])
    {
      spawn_block(22, 23, turn);
      if (turn == true)
      {
        grid[0][2][1] = 1;
      }
      else
      {
        grid[0][2][1] = 0;
      }
      grid[1][2][1] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
    isFinish();
  }
  else if (key == '9')
  {
    if (type > grid[1][2][2])
    {
      spawn_block(43, 23, turn);
      if (turn == true)
      {
        grid[0][2][2] = 1;
      }
      else
      {
        grid[0][2][2] = 0;
      }
      grid[1][2][2] = type;
      decrease_item(type);
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      draw_item(type);
    }
  }else{
    attrset(COLOR_PAIR(1));
    mvaddstr(30, 67, "Can't put");
    attrset(COLOR_PAIR(2));
    draw_item(type);
  }
  // sleep(1);
  mvaddstr(30, 67, "         ");
  mvaddstr(28, 66, "           ");
}
void select_size()
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  mvaddstr(25, 66, "SELECT SIZE");
  mvaddstr(26, 66, "1:S 2:M 3:L");
  refresh();
  noecho();

  if (turn == true)
  {
    // turn = false;
    attrset(COLOR_PAIR(6));
    mvaddstr(2, 68, "Player1");
    attrset(COLOR_PAIR(2));
    mvaddstr(13, 68, "Player2");
  }
  else
  {
    attrset(COLOR_PAIR(5));
    mvaddstr(13, 68, "Player2");
    attrset(COLOR_PAIR(2));
    mvaddstr(2, 68, "Player1");
  }
  int key = getch();
  mvaddstr(28, 68, "      ");
  mvaddstr(30, 67, "         ");
  refresh();
  
  if (key == '1')
  {
    mvaddstr(28, 68, " SMALL");
    if (isExistS())
    {
      mvaddstr(30, 68, "Can put");
      type = set_form(0);
      draw_item(type);
      print_itemNum();
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      select_size();
    }
  }
  else if (key == '2')
  {
    mvaddstr(28, 68, "MEDIUM");
    if (isExistM())
    {
      mvaddstr(30, 68, "Can put");
      type = set_form(1);
      draw_item(type);
      print_itemNum();
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      select_size();
    }
  }
  else if (key == '3')
  {
    mvaddstr(28, 68, " LARGE");
    if (isExistL())
    {
      mvaddstr(30, 68, "Can put");
      type = set_form(2);
      draw_item(type);
      print_itemNum();
    }
    else
    {
      attrset(COLOR_PAIR(1));
      mvaddstr(30, 67, "Can't put");
      attrset(COLOR_PAIR(2));
      select_size();
    }
  }
  else
  {
    attrset(COLOR_PAIR(1));
    mvaddstr(30, 67, "Chose 1~3");
    attrset(COLOR_PAIR(2));
    select_size();
  }
  isFinish();
  if (turn == true)
  {
    turn = false;
  }
  else
  {
    turn = true;
  }
  refresh();
}
void game_main()
{
  draw_board();
  while (1)
  {
    select_size();
  }
}
void start_up()
{
  noecho();
  int key = getch();
  if (key == '0')
  {
    endwin();
  }
  else if (key == '1')
  {
    clear();
    init_window2();
    game_main();
  }
  else if (key == '2')
  {
    help();
    start_up();
  }else{
    start_up();
  }
}