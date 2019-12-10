#include <windows.h>
#include "console.h"
#include <conio.h>
#include <iostream>
#include <string>


int main(void)
{
    std::string m = "Message";
    Message ms(5,5,m,0);
    ms.show();
    while (1) {
        int c = getch();
        if (c == 27){break;}
        if (c == 49){ms.hide();}
        if (c == 50){ms.show();}
        if (c == 51){ms.mMode =0;ms.show();}; //l
        if (c == 52){ms.mMode =1;ms.show();}; //r
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

