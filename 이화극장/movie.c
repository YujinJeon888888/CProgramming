#include <stdio.h>
#include "movie.h"

void �޴����̱�() {

	printf("========================================\n");

	printf("1. �����ϱ� 2. ����ϱ� 3. �¼����̱� 0. ����\n");

	printf("========================================\n");

}


void �¼����̱�(int map[][��]) {

	int i, j;

	for (i = 0; i < ��; i++) {

		printf("[%2d] : ", i + 1);

		for (j = 0; j < ��; j++) {

			if (map[i][j] == 1) {

				printf("��");

			}

			else printf("��");

		}

		printf("\n");

	}

}

void ����ϱ�(int map[][��])
{
	int row, col = 0;

	while (1) {

		printf("����� ��[%d~%d](-1�� ������ �ʱ�ȭ������ ���ư��ϴ�.): ", 1, ��); scanf("%d", &row);
		if (row == -1) return;
		printf("����� ��[%d~%d]: ", 1, ��); scanf("%d", &col);
		
		
		if (map[row - 1][col - 1] == 0) {
			printf("�� �¼��Դϴ�.\n");
			continue;
		}

		if (row<1 || row>��) printf("�Է��� ���� ��ȿ������ �ƴմϴ�. \n");//�ݺ��ϵ�, return �ϵ� ����

		else if (col<1 || col>��) printf("�Է��� ���� ��ȿ������ �ƴմϴ�. \n");

		else break;
	}

	map[row - 1][col - 1] = 0;
	printf("�¼� ��Ұ� �Ϸ�Ǿ����ϴ�.\n");

}



void �����ϱ�(int map[][��]) {

	int row, col = 0;

	while (1) {
		printf("������ ��[%d~%d](-1�� ������ �ʱ�ȭ������ ���ư��ϴ�.): ", 1, ��); scanf("%d", &row);
		if (row == -1) return;
		printf("������ ��[%d~%d]: ", 1, ��); scanf("%d", &col);
		
		if (map[row - 1][col - 1] == 1) {
			printf("�̹� ����Ǿ����ϴ�.\n");
			continue;
		}

		if (row<1 || row>��) printf("�Է��� ���� ��ȿ������ �ƴմϴ�. \n");//�ݺ��ϵ�, return �ϵ� ����

		else if (col<1 || col>��) printf("�Է��� ���� ��ȿ������ �ƴմϴ�. \n");

		else break;
	}

	map[row - 1][col - 1] = 1;
	printf("�¼� ������ �Ϸ�Ǿ����ϴ�.\n");
}
