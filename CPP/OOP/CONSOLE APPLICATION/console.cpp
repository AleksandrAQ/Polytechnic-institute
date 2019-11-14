#include <windows.h>
#include "console.h"
#include <conio.h>
#include <iostream>

void main(void)
{
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int x, y;
  clear_screen();
  set_color(cWHITE, cLIGHTBLUE);
  bar(32, 10, 45, 14);
  rectangle(32,10,45,14);
  set_color(cYELLOW, cLIGHTBLUE);
  set_cursor_pos(34,12);
  std::cout<<"It is all!";
  set_cursor_pos(0,0);
  while(1)
  {
	  click_cursor(x,y);
	  if(x>=32&&x<=47&&y>=10&&y<=14)
		  break;
  }
  set_color(cWHITE, cBLACK);
  set_cursor_pos(0,0);
}

