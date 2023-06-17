#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define ROW_MAX 10
#define COL_MAX 20

//������ ������ �����صδ� ��������
int FLOORS = 0;

void showMenu() {
	printf("----------------------------------------------------------------------------------------------------------------------------------------------- \n");
	printf("   1.��������   2.���������(��)   3.���� �游���   4.���ֽ�Ű��   5.��������   6.�������ֱ�  *7.��ũ�� �����ϱ�  *8.��ũ�� �����ϱ� 0.�����ϱ� \n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------- \n");
}

void showBuilding(char*** bld, char* name) { //name�� �ǹ��̸�

	int i, j, k; //i�� ��, j�� �������


	//��ó��
	if (bld == NULL) {
		printf(" \n �ǹ��� �������� �ʾҽ��ϴ�. \n\n");
		return;
	}

	//���ݺ�, ���ݺ����� �ݺ���ø��
	for (i = 0; i < FLOORS; i++) {//�ǹ� ����ŭ

		k = FLOORS - i; //������ ����ϰų� 
		printf("%10s���� [%d] : ", name, FLOORS - i);

		//i���� �Ҵ�� ���� ���� ���		
		if (bld[i] == NULL) {
			printf("room ���� \n");
			continue;
		}

		for (j = 0; j < _msize(bld[i]) / sizeof(char*); j++) {//���� ��� ��ŭ 
			//������ ������ ��, ������ ��
			if (bld[i][j] == NULL) printf("��");
			else printf("��");
		}
		printf("\n");
	}
}


//���ο��� building�� �����͸� �������� char ****bld�� �ް� ���ϰ������� ����,���� signal�� �����Ѵ�.  
char*** makeFloor(char*** bld) {
	int floor;

	if (bld != NULL) {
		printf("�̹� �ǹ��� ���� �ϼ��Ǿ����ϴ�. ���� ���� ���� �����Դϴ�. \n");
		return bld;
	}

	printf(" \n������ �� ������ ������? ");
	scanf("%d", &floor);

	//�����Ҵ� ����ó��(����ũ�⿩�� �����Ҵ� ����)
	if (floor <= 0 || floor > ROW_MAX) {
		printf("��ȿ�� ũ�Ⱑ �ƴմϴ�. \n");
		return NULL;
	}

	//�����Ҵ��ϰ�
	bld = (char***)malloc(floor * sizeof(char*));
	//�����Ҵ�� ������ �ʱ�ȭ�Ѵ�-> memset(�����ͺ���,�ʱ��Ҵ簪,ũ��)
	memset(bld, 0x0, floor * sizeof(char*)); //0x0�� 16����(���ĺ� O�� �����ϱ� ����) 0->NULL�� �ᵵ ��
	//�������� FLOORS�� ��ũ�� ����, FLOORS = floor�� ����
	FLOORS = _msize(bld) / sizeof(char*); //���� ��� floor��밡��

	printf("\n %d ���� ������ ����������ϴ�. \n\n", FLOORS);

	return bld; //ȣ���� ������ bld����

}
//���ο���  building�� �������� �ʿ��Ͽ� char **bld��
void makeRoom(char*** bld) {
	int floor, room, k;

	if (bld == NULL || FLOORS <= 0) {
		printf("������ ���� ������ּ���. \n");
		return;
	}

	printf("���� ���� ���� �������ּ���.: ");
	scanf("%d", &floor);

	k = FLOORS - floor;
	printf("k-> %d \n", k);   //�ε��� Ȯ�ο� ���

	if (bld[k] != NULL || floor > FLOORS || floor <= 0) {
		printf("�ش� ���� �������� �ʰų� �̹� ���� ��������ֽ��ϴ�. \n");
		return;
	}

	printf("[%d] ���� ���� ���� ������ �������ּ���. : ", floor);
	scanf("%d", &room);

	if (room <= 0 || room > COL_MAX) {
		printf("��ȿ�� ũ�Ⱑ �ƴմϴ�. \n");
		return;
	}
	bld[k] = (char**)malloc(room * sizeof(char*));
	memset(bld[k], 0x0, room * sizeof(char*));
	printf("[%d] ���� %d���� ���� ��������ϴ�. \n", floor, room);
}

void moveIn(char*** bld) {
	int floor, room, k, i;
	char c;

	if (bld == NULL || FLOORS <= 0) {
		printf("������ ���� ������ּ���. \n");
		return;
	}
	printf("������ ���� ���ȣ�� �ùٷ� �Է����ּ���:");
	scanf("%d %d", &floor, &room);
	scanf("%c", &c);

	k = FLOORS - floor;
	i = room - 1;

	//��ȿ�Ѱ�?
	if (k >= FLOORS || bld[k] == NULL || i >= _msize(bld[k]) / sizeof(char*)) {
		printf("�ش� ������ ��ȿ���� �ʽ��ϴ�. ���� �����ϰų� �ùٸ� ��ȣ�� �Է����ּ���. \n");
		return;
	}

	//�̹� ������ ����ִ� �����ΰ�?
	if (bld[k][i] != NULL) {
		printf("�̹� �ٸ� ����� ������ �ֽ��ϴ�. \n"); //���� ���ֹ�����, �������� ���ð���. 
		return;
	}

	bld[k][i] = (char*)malloc(sizeof(char) * 100);
	printf("������ �̸��� �Է��ϼ��� : ");
	gets(bld[k][i]);
	bld[k][i] = (char*)realloc(bld[k][i], strlen(bld[k][i]) + 1);
}

void showFloor(char*** bld) {
	int i, f, room, k;

	if (bld == NULL) {
		printf("������ �������� �ʾҽ��ϴ�. \n");
		return;
	}

	printf("�� ���� ������ �����? ");
	scanf("%d", &f);

	k = FLOORS - f;

	if (bld[k] == NULL || f > FLOORS) {
		printf("�ش� ���� ���ų� �ش� ���� ������� ���� �����ϴ�. \n");
		return;
	}

	room = _msize(bld[k]) / sizeof(char*);  //32��Ʈ������ 4, 64��Ʈ������ 8. 

	for (i = 0; i < room; i++) {
		printf("room[%d] : ", i + 1);
		if (bld[k][i] == NULL) printf("�� : -- \n");
		else printf("�� : %s \n", bld[k][i]);
	}
	printf("\n");
}

int main() {

	char*** building = NULL; // ***�� ���� 2�����迭�� ��(1),��(2) �����ϰ�  �� ���� ���ڿ�(3)���� �����ϱ� ����
	int menu, floor = 0, room;
	char name[10];
	char YorN;

	int i, k;

	printf("��ȭ����繫�ҿ� ���� �� ȯ���մϴ�! \n\n\n");
	printf("������ �̸��� �����ּ���(10�� �̳�) : ");
	//scanf("%s", name); //�迭�̹Ƿ� &��� �� �� , ���� ������
	gets(name); //���� ����
	printf("\n '%s'������ ������ �����ϰڽ��ϴ�. \n\n", name);

	while (1) {
		showMenu();
		printf("menu: ");
		scanf("%d", &menu);

		//if ���switch�� ��뵵 ���� & menu 6��� �����
		if (menu == 0) {
			printf("�ǹ� ������ �����մϴ�. ��ȭ����繫���� �̿����ּż� �����մϴ�! \n");
			break;
		}

		if (menu == 1) showBuilding(building, name);
		else if (menu == 2) building = makeFloor(building);
		//���ϰ��� ���� ���·� ������� &building�� �����Ѵ�.   makeFloor(&building);  

		else if (menu == 3) makeRoom(building);
		else if (menu == 4) moveIn(building);
		else if (menu == 5) showFloor(building);
		else if (menu == 6) {
			//�� �κ��� �ϼ��Ͽ� �Լ��� ����� ���ϴ�. 
			//destroyBuilding(&building);

	  ///////////////////////////////////////////////////////
			printf("������ ���ֽðڽ��ϱ�?(Y/N) ");
			scanf("%c", &YorN);

			while (YorN != 'Y' && YorN != 'N') {
				printf("Y / N ���� ������ �����ּ���. : ");
				scanf("%c", &YorN);
			}

			if (YorN == 'Y') {

				//���� ���ʰ������� �ݳ��մϴ�.  ��->��->�ǹ������� free�ϼ���.
					  //�������� �Ҵ���� ���� free���� �ʰ� �������� ���Ƹ�, �������� garbage�� �˴ϴ�.-> �޸� ����!
				for (i = 0; i < FLOORS; i++) {
					free(building[i]);
					building[i] = NULL;
				}
				free(building);
				building = NULL;

				printf("������ ���ʶ߷Ƚ��ϴ�.\n");
				FLOORS = 0;
			}

			else 	printf("���� ���ֱ⸦ ����ϼ̽��ϴ�. \n");

		}
	}
	return 0;

}