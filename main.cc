#include <Game.h>
#include <curses.h>

using namespace std;

int main(void) 
{
  initscr();
  start_color();

  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW,COLOR_BLACK);
  attron(COLOR_PAIR(1));
  printw("Var hälsad\n");
  printw("Välkommen till Byakungen!\n");
  
  attron(COLOR_PAIR(3));
  printw(" _.+._ \n");
  printw("(^\/^\/^)\n");
  printw("\\@*@*@/\n");
  printw("{_____}\n");     
 
  attron(COLOR_PAIR(2));
  printw("Nu kommer du få gå på ditt livsäventyr!\n");

  refresh();

  getch();

  endwin();

  for(unsigned int i{0}; i < 5; ++i)
    {
      cout << i << endl:
    }


}
