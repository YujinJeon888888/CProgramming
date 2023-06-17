#include "기본함수들.h"

//1. 커서의 위치를 바꾸는 함수, 위치를 알려주는 함수
//커서를 해당 위치로 이동하는 함수
void gotoXY(int _x, int _y) {
	COORD pos = { _x,_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서의 x,y위치를 알려주는 함수
COORD getXY(void) {
	COORD pos;
	CONSOLE_SCREEN_BUFFER_INFO curInfor;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	pos.X = curInfor.dwCursorPosition.X;
	pos.Y = curInfor.dwCursorPosition.Y;

	return pos;
}

//2. 화면을 지우는 함수
void clear(void) {
	system("cls");
}

//3. 타이틀을 변경하는 함수
void setTitle(char* _szConsoleName) {//포인터: 주소넘김
	SetConsoleTitle(_szConsoleName);
}

//4. 글자색, 배경색을 변경하는 함수
//배경색 0~15, 글자색 0~15까지 16색 사용해서 변경하는 함수
void setColor(unsigned char _BgColor, unsigned char _TextColor) {
	if (_BgColor > 15 || _TextColor > 15) return;//유효한범위x

	//배경색과 글자색을 동시에 설정하는 함수-high 4bit: 배경색, low 4bit: 글자색
	//0x00f0이면 f는 흰색 배경, 0은 검정 글씨
	unsigned short ColorNum = ( _BgColor << 4 ) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);

}

//5. 커서를 보이게 하거나 (true) 보이지 않게 하는 함수(false)
//커서를 보이게 안보이게 하는 함수
void setInvisibleCursor() {
	//깜박거리는 커서 없애기
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;//커서로 채워진 문자 셀의 백분율. 높이
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//6. 콘솔창의 크기를 변경하는 방법
/**system("mode con cols=80 lines=25");  // 가로 80, 세로 25의 콘솔창 크기 변경*/
void setConsoleSize(int _col, int _lines) {
	char setText[100];
	//파일이나 화면에 출력하는 것이 아니라 변수(버퍼)에 문자열을 출력한다.
	sprintf(setText, "mode con cols=%d lines=%d", _col,_lines);
	system(setText);
}


//글자색, 배경색을 변경하는 예제 프로그램
//int main() {
//	for (int i = 0; i < 16; i++) {
//		setColor(i, 0);
//		printf("Background Color: %d \t", i);
//		setColor(0, i);
//		printf("Text Color: %d \n", i);
//	}
//	system("pause");//어떤 키를 누르면 다음 동작으로 넘어간다. 
//
//	return 0;
//}