#include <stdio.h>
#include "movie.h"

int main() {

	int map[행][열]={0};
	int menu;
	printf("*****************************************\n");
	printf("\t\t이화극장\n");
	printf("*****************************************\n");

	while (1)
	{
		메뉴보이기();

		printf("메뉴: ");
		scanf("%d", &menu);

		if (menu == 1) 예약하기(map);
		if (menu == 2) 취소하기(map);
		if (menu == 3) 좌석보이기(map);
		if (menu == 0) {
			printf("이화극장을 이용해주셔서 감사합니다.\n");
			break;
		}
	}

	return 0;

}

