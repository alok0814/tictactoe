#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <random>
#include <time.h>
#include"func1.h"
#include"setup.h"
#include"define.h"

#define WINDOW_X 80
#define WINDOW_Y 34

bool isExistL()
{
  bool ans = false;
  if (turn == true)
  {
    if (p1_large > 0)
    {
      return true;
    }
  }
  else
  {
    if (p2_large > 0)
    {
      return true;
    }
  }
  return ans;
}
bool isExistM()
{
  bool ans = false;
  if (turn == true)
  {
    if (p1_medium > 0)
    {
      return true;
    }
  }
  else
  {
    if (p2_medium > 0)
    {
      return true;
    }
  }
  return ans;
}
bool isExistS()
{
  bool ans = false;
  if (turn == true)
  {
    if (p1_small > 0)
    {
      return true;
    }
  }
  else
  {
    if (p2_small > 0)
    {
      return true;
    }
  }
  return ans;
}
bool isDraw()
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  char p3[] = "   DRAW    ";
  if (p1_large == 0 && p1_medium == 0 && p1_small == 0 && p2_large == 0 && p2_medium == 0 && p2_small == 0)
  {
    clear();
    attrset(COLOR_PAIR(1));
    mvprintw(WINDOW_Y / 3, WINDOW_X / 2 - (strlen(p3) / 2), "%s", p3);
    attrset(COLOR_PAIR(2));
    return true;
  }
  return false;
}
bool isWin()
{
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  char p1[] = "PLAYER1 WIN";
  char p2[] = "PLAYER2 WIN";
  if (grid[0][0][0] * grid[0][0][1] * grid[0][0][2] == 1 || grid[0][1][0] * grid[0][1][1] * grid[0][1][2] == 1 || grid[0][2][0] * grid[0][2][1] * grid[0][2][2] == 1 || grid[0][0][0] * grid[0][1][0] * grid[0][2][0] == 1 || grid[0][0][1] * grid[0][1][1] * grid[0][2][1] == 1 || grid[0][0][2] * grid[0][1][2] * grid[0][2][2] == 1 || grid[0][0][0] * grid[0][1][1] * grid[0][2][2] == 1 || grid[0][0][2] * grid[0][1][1] * grid[0][2][0] == 1)
  {
    clear();
    win = true;
    attrset(COLOR_PAIR(6));
    mvprintw(WINDOW_Y / 3, WINDOW_X / 2 - (strlen(p1) / 2), "%s", p1);
    attrset(COLOR_PAIR(2));
    return win;
  }
  else if (grid[0][0][0] + grid[0][0][1] + grid[0][0][2] == 0 || grid[0][1][0] + grid[0][1][1] + grid[0][1][2] == 0 || grid[0][2][0] + grid[0][2][1] + grid[0][2][2] == 0 || grid[0][0][0] + grid[0][1][0] + grid[0][2][0] == 0 || grid[0][0][1] + grid[0][1][1] + grid[0][2][1] == 0 || grid[0][0][2] + grid[0][1][2] + grid[0][2][2] == 0 || grid[0][0][0] + grid[0][1][1] + grid[0][2][2] == 0 || grid[0][0][2] + grid[0][1][1] + grid[0][2][0] == 0)
  {
    clear();
    win = true;
    attrset(COLOR_PAIR(5));
    mvprintw(WINDOW_Y / 3, WINDOW_X / 2 - (strlen(p2) / 2), "%s", p2);
    attrset(COLOR_PAIR(2));
    return win;
  }
  return win;
}
void isFinish()
{
  if (isWin() == true || isDraw() == true)
  {
    refresh();
    char p3[] = "RETRY AGAIN ?";
    char p4[] = "YES:R NO:Q";
    mvprintw(WINDOW_Y / 2 + 1, WINDOW_X / 2 - (strlen(p3) / 2), "%s", p3);
    mvprintw(WINDOW_Y / 2 + 3, WINDOW_X / 2 - (strlen(p4) / 2), "%s", p4);
    refresh();
    noecho();
    int key = getch();
    if (key == 'q')
    {
      endwin();
      exit(-1);
    }
    else if (key == 'r')
    {
      clear();
      turn = true;
      win = false;
      p1_large = 2;
      p1_medium = 2;
      p1_small = 2;
      p2_large = 2;
      p2_medium = 2;
      p2_small = 2;
      for (int i = 0; i < 3; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          grid[1][i][j] = -1;
        }
      }
      int k = 10;
      for (int i = 0; i < 3; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          srand((unsigned int)time(NULL));
          grid[0][i][j] = k;
          k++;
        }
      }
      game_main();
    }else{
      isFinish();
    }
  }
}
