#include "��.h"

void ����(Enemy *e,Player *p) {
	int i;
	char ID[20] = "";
	system("cls");
	gotoXY(0, 0);
	setColor(0, 14);
	for (i = 0; i < ���α��� / 2; i++) {
		printf("��");
	}
	gotoXY(0, ���α��� - 1);
	for (i = 0; i < ���α��� / 2; i++) {
		printf("��");
	}
	if ((*e).hp <= 0) {
		gotoXY((���α��� / 2) - 14, 0);
		setColor(0, 15);
		printf("������ �׿����. ��ȣ!!\n\n\n");
		printf("���̵� �Է��ϼ���: ");
	}
	else {
		gotoXY((���α��� / 2) - 4, 0);
		setColor(0, 15);
		printf("�׾����\n\n\n");
		printf("���̵� �Է��ϼ���: ");
	}
	//����: �Լ����� �̻��ؿ�: _s���ؼ�.  
	gets_s(ID, 20);//���̵� ����
	�������Ͽ���(&(*p), ID);//����: include���ߴµ� ���ư���, include�ϸ� ��������.: paragma once
	
	system("pause");
}

void ����ȭ��() {
	int i;
	char answer=0;
	char buffer[20] = "";
	system("cls");
	while (1) {
		gotoXY(0, 0);
		setColor(0, 14);
		for (i = 0; i < ���α��� / 2; i++) {
			printf("��");
		}
		gotoXY(0, ���α��� - 1);
		for (i = 0; i < ���α��� / 2; i++) {
			printf("��");
		}


		gotoXY((���α��� / 2) - 10, 0);
		setColor(0, 15);
		printf("���� vs �÷��̾�\n\n\n");

		setColor(0, 3);
		gotoXY(���α��� / 2 - 12, 6);
		printf("�����ˣ����ˣ���\n");
		gotoXY((���α��� / 2 - 12) - 5, 6 + 1);
		printf("  ��������������������\t\t");
		setColor(0, 14);
		printf("���ȴ��ݡ�\n");
		setColor(0, 3);
		gotoXY((���α��� / 2 - 12) - 4, 6 + 2);
		printf("     @�����������\n\n\n\n\n");


		setColor(0,2);
		printf("\t\t\t�����Ϸ��� �����̽�Ű�� �Է��ϼ���: ");
		scanf("%c", &answer);
		if (answer==' ') {
			gets_s(buffer, 20);//���۸Ա�
			return;
		}
		else {
			system("cls");
			gets_s(buffer, 20);//���۸Ա�
			continue;
		}
	}
}