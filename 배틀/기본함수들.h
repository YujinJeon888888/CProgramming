#include <stdio.h>
#include <windows.h>

void gotoXY(int _x, int _y);
COORD getXY(void);
void clear(void);
void setTitle(char* _szConsoleName);
void setColor(unsigned char _BgColor, unsigned char _TextColor);
void setInvisibleCursor();
void setConsoleSize(int _col, int _lines);
