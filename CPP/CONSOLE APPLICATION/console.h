#ifndef _INC_WCONSOLE    //don't let this file be included
#define _INC_WCONSOLE    //twice in the same source file

#include <windows.h>
#include <conio.h>
#include <iostream>

enum cCOLOR{cBLACK, cBLUE, cGREEN, cCYAN,
	cRED, cMAGENTA, cBROWN, cLIGHTGRAY,
	cDARKGRAY, cLIGHTBLUE, cLIGHTGREEN, cLIGHTCYAN,
	cLIGHTRED, cLIGHTMAGENTA, cYELLOW, cWHITE};

void set_color(cCOLOR fg, cCOLOR bg = cBLACK);
// x - position, y - row
void set_cursor_pos(int x, int y);
void get_cursor_pos(int &x, int &y);
void clear_screen(void);
void rectangle(int left, int top, int right, int bottom);
void bar(int left, int top, int right, int bottom);
void wait(int milliseconds);
void clear_line(int row);
int  click_cursor(int &x, int &y);                          //*

HANDLE hConsole;         //console handle
//--------------------------------------------------------------
void set_color(cCOLOR foreground, cCOLOR background)
{
  SetConsoleTextAttribute( hConsole, 
                       (WORD)((background << 4) | foreground) );
}
//--------------------------------------------------------------
void get_cursor_pos(int &x, int &y)
{
  CONSOLE_SCREEN_BUFFER_INFO inf;
  GetConsoleScreenBufferInfo(hConsole,&inf);
  x=inf.dwCursorPosition.X;
  y=inf.dwCursorPosition.Y;
}
//--------------------------------------------------------------
void set_cursor_pos(int x, int y)
{
  COORD cursor_pos;
  cursor_pos.X = x;
  cursor_pos.Y = y;
  SetConsoleCursorPosition(hConsole, cursor_pos);
}
//--------------------------------------------------------------
void rectangle(int left, int top, int right, int bottom)
{
  int tmp,row,col;

  if(left>right)
  { tmp=left; left=right; right=tmp; }
  if(top>bottom)
  { tmp=top; top=bottom; bottom=tmp; }
  
  set_cursor_pos(left,top);     std::cout<<'\xDA';
  set_cursor_pos(right,top);    std::cout<<'\xBF';
  set_cursor_pos(right,bottom); std::cout<<'\xD9';
  set_cursor_pos(left,bottom);  std::cout<<'\xC0';

  col=left+1;
  set_cursor_pos(col,top);
  for(;col<right;col++)
    std::cout<<'\xC4';

  col=left+1;
  set_cursor_pos(col,bottom);
  for(;col<right;col++)
    std::cout<<'\xC4';

  row=top+1;
  for(;row<bottom;row++)
  {
    set_cursor_pos(left,row);
    std::cout<<'\xB3';
  }

  row=top+1;
  for(;row<bottom;row++)
  {
    set_cursor_pos(right,row);
    std::cout<<'\xB3';
  }
}
//--------------------------------------------------------------
void bar(int left, int top, int right, int bottom)
{
  int tmp,row,i;
  char s[100];
    if(left>right)
  { tmp=left; left=right; right=tmp; }
  if(top>bottom)
  { tmp=top; top=bottom; bottom=tmp; }

  for(i=0;i<=(right-left);i++)
    s[i]=' ';
  s[i]='\0';
  for(row=top;row<=bottom;row++)
  {
    set_cursor_pos(left,row);
    std::cout<<s;
  }
}
//--------------------------------------------------------------
void clear_screen(void)
{
  set_cursor_pos(0,0);
  for(int j=0; j<=24; j++)
  	clear_line(j);
  set_cursor_pos(0, 0);
}
//--------------------------------------------------------------
void wait(int milliseconds)
{
  Sleep(milliseconds);
}
//--------------------------------------------------------------
void clear_line(int row)
{
  set_cursor_pos(0,row);
   //.....1234567890123456789012345678901234567890
   //.....0........1.........2.........3.........4 
  _cputs("                                        ");
  _cputs("                                        ");
}
//--------------------------------------------------------------
int click_cursor(int &x, int &y)
{
  int i;
  CONSOLE_CURSOR_INFO inf;
  inf.dwSize=55;
  SetConsoleCursorInfo(hConsole,&inf);
  get_cursor_pos(x,y);
  while(1)
  {
    set_cursor_pos(x,y);
    i=_getch();
    if(i==224||i==0)
      i=1000+_getch();
    switch(i)
    {
      case   27:   //Esc
        inf.dwSize=25;
        SetConsoleCursorInfo(hConsole,&inf);
        return 0;
      case   13:   //Enter
        inf.dwSize=25;
        SetConsoleCursorInfo(hConsole,&inf);
        return 1;
      case 1080:   //Down
        if(y<24)
          y++;    
        break;
      case 1072:   //Up
        if(y>0)
          y--;    
        break;
      case 1075:   //<--
        if(x>0)
          x--;    
        break;
      case 1077:   //-->
        if(x<79)
          x++;    
    }
  }
}
//--------------------------------------------------------------
#endif /* _INC_WCONSOLE */
