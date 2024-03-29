#include <stdio.h>
#define SIZE 15

//아래 왼쪽으로 회전하기 위한 함수를 작성하세요
void rotate_left(int img[][SIZE], int target[][SIZE]) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			target[SIZE - 1 - j][i] = img[i][j];
		}
	}

}

//2차배열을 출력하는 함수를 작성하세요
//0은 ○  1은 ●로 표시합니다.
void show_image(int img[][SIZE]) {
	//조건에 따라 아래 문자를 출력하는 반복문을 작성하세요
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (img[i][j] == 1)	printf("●");
			else	printf("○");
		}
		printf("\n");
	}



}



int main() {

	int smile[SIZE][SIZE] = {
{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 } ,
{ 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 } ,
{ 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 0 , 1 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 } ,
{ 0 , 0 , 1 , 0 , 0 , 0 , 1 , 1 , 1 , 0 , 0 , 0 , 1 , 0 , 0 } ,
{ 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 } ,
{ 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
	};

	int smile_left[SIZE][SIZE] = { 0 };


	//회전함수 호출
	rotate_left(smile[SIZE][SIZE], smile_left[SIZE][SIZE]);
	//출력함수 호출
	show_image(smile_left[SIZE][SIZE]);
	return 0;
}
