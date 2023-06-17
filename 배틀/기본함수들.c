#include "�⺻�Լ���.h"

//1. Ŀ���� ��ġ�� �ٲٴ� �Լ�, ��ġ�� �˷��ִ� �Լ�
//Ŀ���� �ش� ��ġ�� �̵��ϴ� �Լ�
void gotoXY(int _x, int _y) {
	COORD pos = { _x,_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Ŀ���� x,y��ġ�� �˷��ִ� �Լ�
COORD getXY(void) {
	COORD pos;
	CONSOLE_SCREEN_BUFFER_INFO curInfor;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
	pos.X = curInfor.dwCursorPosition.X;
	pos.Y = curInfor.dwCursorPosition.Y;

	return pos;
}

//2. ȭ���� ����� �Լ�
void clear(void) {
	system("cls");
}

//3. Ÿ��Ʋ�� �����ϴ� �Լ�
void setTitle(char* _szConsoleName) {//������: �ּҳѱ�
	SetConsoleTitle(_szConsoleName);
}

//4. ���ڻ�, ������ �����ϴ� �Լ�
//���� 0~15, ���ڻ� 0~15���� 16�� ����ؼ� �����ϴ� �Լ�
void setColor(unsigned char _BgColor, unsigned char _TextColor) {
	if (_BgColor > 15 || _TextColor > 15) return;//��ȿ�ѹ���x

	//������ ���ڻ��� ���ÿ� �����ϴ� �Լ�-high 4bit: ����, low 4bit: ���ڻ�
	//0x00f0�̸� f�� ��� ���, 0�� ���� �۾�
	unsigned short ColorNum = ( _BgColor << 4 ) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);

}

//5. Ŀ���� ���̰� �ϰų� (true) ������ �ʰ� �ϴ� �Լ�(false)
//Ŀ���� ���̰� �Ⱥ��̰� �ϴ� �Լ�
void setInvisibleCursor() {
	//���ڰŸ��� Ŀ�� ���ֱ�
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;//Ŀ���� ä���� ���� ���� �����. ����
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//6. �ܼ�â�� ũ�⸦ �����ϴ� ���
/**system("mode con cols=80 lines=25");  // ���� 80, ���� 25�� �ܼ�â ũ�� ����*/
void setConsoleSize(int _col, int _lines) {
	char setText[100];
	//�����̳� ȭ�鿡 ����ϴ� ���� �ƴ϶� ����(����)�� ���ڿ��� ����Ѵ�.
	sprintf(setText, "mode con cols=%d lines=%d", _col,_lines);
	system(setText);
}


//���ڻ�, ������ �����ϴ� ���� ���α׷�
//int main() {
//	for (int i = 0; i < 16; i++) {
//		setColor(i, 0);
//		printf("Background Color: %d \t", i);
//		setColor(0, i);
//		printf("Text Color: %d \n", i);
//	}
//	system("pause");//� Ű�� ������ ���� �������� �Ѿ��. 
//
//	return 0;
//}