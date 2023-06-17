#include <stdio.h>



struct ������������
{
	char title[50];
	char prof[30];
	int score;
};

struct ����
{
	int year;
	int month;
	int day;
};

typedef struct �л�
{
	char �а�[50];
	int  �й�;
	int �г�;
    char �̸�[10];
	struct ���� birth;
	int �������񰳼�;
	struct ������������ sbjInfo;
}STD;

void ����ϱ�(STD s[], int n) {


    int i;

    printf("----------------------------------------------------------------------------\n");
    printf(" No.        �а�           �й�        �г�    �̸�  \n");
    printf("----------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%d", i + 1);
        printf("%20s  %d        %3d    %5s \n", s[i].�а�, s[i].�й�, s[i].�г�, s[i].�̸�);
    }

    printf("----------------------------------------------------------------------------\n");
    printf("         ����⵵          �����        �����    ���������  \n");
    printf("----------------------------------------------------------------------------\n");
    //������ �κ�: 
    //����ü�� ����� ���� ����ü
    for (i = 0; i < n; i++) {
        printf("%4d       %2d        %2d    %5d \n", s[i].birth.year, s[i].birth.month, s[i].birth.day, s[i].�������񰳼�);
    }

    printf("----------------------------------------------------------------------------\n");
    printf("         ����           ����        ����    \n");
    printf("----------------------------------------------------------------------------\n");
    //������ �κ�: 
   //����ü�� ����� ���� ����ü
    for (i = 0; i < n; i++) {
        printf("%20s  %10d        %3d    \n", s[i].sbjInfo, s[i].�й�, s[i].�г�);
    }


    printf("----------------------------------------------------------------------------\n");

}
void �����б�(char* filename, STD s[], int* n) {
    FILE* fp = NULL;//�η� �ʱ�ȭ
    fp = fopen(filename, "r");//���� �������� �����Ѵ�, r: read���̴�. 
    char name[100] = "";
    int i = 0;


    if (fp == NULL) {//�� ������ null����
        printf("ȭ���б� ���� ���α׷��� �����մϴ�. \n");
        exit(1);
    }
    printf("�л� ���� �Է��ϼ��� ^^:");
    scanf("%d", n);//&�Ⱥ��̴� ����: �����ͺ����ϱ� 

    while (1) {
        //ȭ���� ���� �����ϸ� 0�� �ƴ� ���� ������.        
        if (feof(fp) != 0)  break;//���� �����ߴ�->�ݺ��� ������. 
        if (i == *n) break;//�л� �������� �д´�. 
        fscanf(fp, "%s", s[i].�а�);
        fscanf(fp, "%d", &s[i].�й�);
        fscanf(fp, "%d", &s[i].�г�);
        fscanf(fp, "%s", s[i].�̸�);

        //������ �κ�: �������� ����(�������� :����ü)
        fscanf(fp, "%d", &s[i].birth.year);
        fscanf(fp, "%d", &s[i].birth.month);
        fscanf(fp, "%d", &s[i].birth.day);

        //���������
        fscanf(fp, "%d", &s[i].�������񰳼�);

        //��������
        fscanf(fp, "%s", s[i].sbjInfo.title);
        fscanf(fp, "%s", s[i].sbjInfo.prof);
        fscanf(fp, "%d", &s[i].sbjInfo.score);


      
        
        i++;
    }

    //ȭ���� ��� �о��µ� �л� ������ ���ٸ� �ٽ� ����
    if (i < *n) {
        printf("ȭ�Ͽ��� �о�� �л� ���� �����մϴ�.! \n");
        *n = i;//n�� ���� �ٲ۴�. *���� ����
    }
}

void showMenu() {
    printf("===================================\n");
    printf("1. �����б� 2. ����ϱ� 0. ����\n");
    printf("===================================\n");
}

int main() {
	STD s[100] = { 0 };
	int i, numOfStd;//�л���
    int menu;
    char ȭ���̸�[100] = "�л�����.txt";

    while (1) {
        showMenu();
        printf("�޴��� �Է��ϼ��� : ");
        scanf("%d", &menu);

        if (menu == 0) break;
        if (menu == 1) {
            �����б�(ȭ���̸�, s, &numOfStd);
        }
        if (menu == 2) ����ϱ�( s, &numOfStd);
      

        printf("\n");
    }

    printf("�л����� �ý����� �����մϴ�.");
	
	return 0;
}