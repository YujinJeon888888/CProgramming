#include <stdio.h>
#include "movie.h"

void 메뉴보이기() {

	printf("========================================\n");

	printf("1. 예약하기 2. 취소하기 3. 좌석보이기 0. 종료\n");

	printf("========================================\n");

}


void 좌석보이기(int map[][열]) {

	int i, j;

	for (i = 0; i < 행; i++) {

		printf("[%2d] : ", i + 1);

		for (j = 0; j < 행; j++) {

			if (map[i][j] == 1) {

				printf("■");

			}

			else printf("□");

		}

		printf("\n");

	}

}

void 취소하기(int map[][열])
{
	int row, col = 0;

	while (1) {

		printf("취소할 행[%d~%d](-1을 누르면 초기화면으로 돌아갑니다.): ", 1, 행); scanf("%d", &row);
		if (row == -1) return;
		printf("취소할 열[%d~%d]: ", 1, 열); scanf("%d", &col);
		
		
		if (map[row - 1][col - 1] == 0) {
			printf("빈 좌석입니다.\n");
			continue;
		}

		if (row<1 || row>행) printf("입력한 행이 유효범위가 아닙니다. \n");//반복하든, return 하든 자유

		else if (col<1 || col>열) printf("입력한 열이 유효범위가 아닙니다. \n");

		else break;
	}

	map[row - 1][col - 1] = 0;
	printf("좌석 취소가 완료되었습니다.\n");

}



void 예약하기(int map[][열]) {

	int row, col = 0;

	while (1) {
		printf("예약할 행[%d~%d](-1을 누르면 초기화면으로 돌아갑니다.): ", 1, 행); scanf("%d", &row);
		if (row == -1) return;
		printf("예약할 열[%d~%d]: ", 1, 열); scanf("%d", &col);
		
		if (map[row - 1][col - 1] == 1) {
			printf("이미 예약되었습니다.\n");
			continue;
		}

		if (row<1 || row>행) printf("입력한 행이 유효범위가 아닙니다. \n");//반복하든, return 하든 자유

		else if (col<1 || col>열) printf("입력한 열이 유효범위가 아닙니다. \n");

		else break;
	}

	map[row - 1][col - 1] = 1;
	printf("좌석 예약이 완료되었습니다.\n");
}
