#include <stdio.h>
#include "movie.h"

int main() {

	int map[��][��]={0};
	int menu;
	printf("*****************************************\n");
	printf("\t\t��ȭ����\n");
	printf("*****************************************\n");

	while (1)
	{
		�޴����̱�();

		printf("�޴�: ");
		scanf("%d", &menu);

		if (menu == 1) �����ϱ�(map);
		if (menu == 2) ����ϱ�(map);
		if (menu == 3) �¼����̱�(map);
		if (menu == 0) {
			printf("��ȭ������ �̿����ּż� �����մϴ�.\n");
			break;
		}
	}

	return 0;

}

