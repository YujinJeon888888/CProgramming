#pragma once//�ߺ� ����+�ߺ������� if then else�� �ʿ���
#include "�⺻�Լ���.h"
#include <time.h>
#include "��Ʋ�Լ�.h"
#include "�����Լ�.h"
#include "��.h"

//����: 
//typedef��߸� main������ ������ �� �ִ� ���� ?(�׳� struct���� �� ���� �ȵǴ���
//typedef���ϱ� ��
//: typedef�� �� ����� � �ܾ�� �����Ѵٴ� �ǹ̿���
//struct ~~�� ���� ������ �� struct �ٿ���� ��.

//����: 
//0. �⸻��� ���ǽ� ����������?: ���� ���ǽ� 

float g_second;

int main() {
	
	int i = 0, j = 0;//�ε�����
	int r;
	
	int makeSkillFlag=0;

	//��	
	Enemy e = {0,0,NULL,0,10000};
	Bullet eb[ENEMY_MAX+20] = { 0,0,0,10 };
	for (i = 0; i < ENEMY_MAX; i++) {
		eb[i].power = 10;
	}
	
	//�� ��ų
	Bullet **es = { 0};
	
	//�÷��̾�	
	Player p = { 14,28,NULL,0,100 };
	//�Ѿ�
	Bullet b[PLAYER_MAX] = { 0 };
	for (i = 0; i < PLAYER_MAX; i++) {
		b[i].power = 10;
	}

	//��ų ������ �㿩�ֱ�
	e.skill = &es;
	//�Ѿ� �÷��̾����� �㿩�ֱ�
	p.bullet = &b;
	//�Ѿ� ������ �㿩�ֱ�
	e.bullet = &eb;
	
	//�����õ�
	srand(time(NULL));

	//�ܼ�âũ��
	setConsoleSize(���α���, ���α���);

	//getch: �Է��� ���������� ��ٸ�->���ӿ��� ����ġ �ʴ�.(���ŷ)
	//kbhit: �� ������ �����ְ� ������ �׳� ���.(����ŷ)
	//GetAsyncKeyState: � Ű�� � �������� ���� �޾ƿ´�. 
	/*���ϰ���
		0       :   ���� �� ������ ��Ȳ

		0x8000 : ȣ�� �� ������ ���� ȣ�� ������ ���� ����

		0x8001 : ȣ�� �� ���� �ְ� ȣ�� �������� ���� ����

		1 : ȣ�� �� ������ �ְ� ȣ�� �������� �� ���� ����
	*/

	showEnemy(&e);
	
	//����ȭ��
	����ȭ��();

	while (1) {//���� ���� �� �������̶�� ��������
		clear();//�ܻ� �����(���� ������ ��). �����Ӹ��� ���Ӱ� �������ϴϱ�
		setInvisibleCursor();//Ŀ�� �� ���̰�
		
		//�� ��Ÿ����
		showEnemyBullet(&e);

		//Ű �Է¹ޱ�(�÷��̾��̵�)
		movePlayer(&p);

		//Ű �Է¹ޱ�(�Ѿ˹߻�)
		//�����̽� ������ �Ѿ� �߻�
		shoot(&p, &e);

		//�� ����Ʈ
		printEnemy(&e);
		printEnemyBullet(&p, e);

		//�� �����
		makeWall();

		//���� ���
		printState(p,e);

		//�÷��̾� ���
		printPlayer(&p);

		//��ų ���
		//���ܻ��ܼ��ߴ�
		//r = rand() %10;
		//
		//if (e.hp <= 2000&&r==0) {
		//	if (makeSkillFlag == 0) {
		//		makeSkill(&es);
		//		makeSkillFlag = 1;//�ѹ� ��������� �� ���������.
		//	}
		//	else
		//	{
		//		showEnemySkill(&e.skill);
		//		printEnemySkill(& p, &e.skill);
		//	}
		//}
		

		Sleep(100);//���� ���� �� �ְ� �ӵ�����(�����Ӽӵ�)
		//������
		if (p.hp <= 0) {
			break;//�ݺ���Ż��
		}
		else if (e.hp <= 0) {//���� ���̸�
			break;//�ݺ��� Ż��
		}
	}

	//����
	����(&e, &p);
	
	return 0;
}