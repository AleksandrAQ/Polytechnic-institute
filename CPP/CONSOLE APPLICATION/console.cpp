#include <windows.h>
#include "console.h"
#include <conio.h>
#include <iostream>

class Message
{
public:
    Message() {

    }
    void show(int mod)
    {
        set_color(cWHITE, cLIGHTBLUE);
        bar(32, 10, 45, 14);
        if(mod)
        {
          rectangle(32,10,45,14);
        }
        set_color(cYELLOW, cLIGHTBLUE);
        set_cursor_pos(34,12);
        std::cout<<"Hello world";
        set_color(cWHITE, cBLACK);
    }
    void hide()
    {
        clear_screen();
    }
    void stop()
    {
        set_color(cWHITE, cBLACK);
    }
};

int main(void)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int x, y;
    Message m;
    int mod = 0;
    while (1) {
        int c = getch();
        if (c == 72) //up
        {
            m.show(mod);
        }
        if (c == 80) //dw
        {
            clear_screen();
        }
        if (c == 75) //left
        {
            clear_screen();
            mod = 0;
            m.show(mod);
        }
        if (c == 77) //right
        {
            clear_screen();
            mod = 1;
            m.show(mod);
        }
        if (c == 27) //esc
        {
            m.stop();
            break;
        }

    }
    /*
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int x, y;
  clear_screen();
  set_color(cWHITE, cLIGHTBLUE);
  bar(32, 10, 45, 14);
  rectangle(32,10,45,14);
  set_color(cYELLOW, cLIGHTBLUE);
  set_cursor_pos(34,12);
  std::cout<<"123i";
  set_cursor_pos(0,0);
  while(1)
  {
	  click_cursor(x,y);
	  if(x>=32&&x<=47&&y>=10&&y<=14)
		  break;
  }
  set_color(cWHITE, cBLACK);
  set_cursor_pos(0,0);
*/
}

