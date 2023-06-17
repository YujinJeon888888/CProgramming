#include "��Ʋ�Լ�.h"
#include "�⺻�Լ���.h"

extern float g_second;
int g_firstMakeCheck=0;
int g_enemy_max = ENEMY_MAX;
int g_enemyDirection = 1;

void makeSkill(Bullet*** skill) {//���κ��� ���κ� ���������� ������ ���
	int i,j;
	//���ʺ����� ���� Ÿ�� �� ���� ���ؼ� ����������(3��)
	*skill = (Bullet**)malloc(ENEMY_MAX * sizeof(Bullet*));//�ּҸ� �Ѱ��ִ°Ŵϱ� ��2��
	//�����Ҵ�� ������ �ʱ�ȭ�Ѵ�-> memset(�����ͺ���,�ʱ��Ҵ簪,ũ��)
	memset(*skill, 0x0, ENEMY_MAX * sizeof(char*)); //0x0�� 16����(���ĺ� O�� �����ϱ� ����) 0->NULL�� �ᵵ ��
	for (i = 0; i < ENEMY_MAX; i++) {		
		(*skill)[i] = (Bullet*)malloc(ENEMY_MAX * sizeof(Bullet));
		memset((*skill)[i], 0x1, ENEMY_MAX * sizeof(Bullet)); //0x0�� 16����(���ĺ� O�� �����ϱ� ����) 0->NULL�� �ᵵ ��
	}

	for (i = 0; i < ENEMY_MAX; i++) {
		for (j = 0; j < ENEMY_MAX; j++) {
			(*skill)[i][j].power = 10;
			(*skill)[i][j].active = 0;
		}
	}
}

void showEnemySkill(Bullet*** skill) {
	int i,j;
	int iR,jR;

	srand(time(NULL));

	iR = rand() % ���κ�;
	jR = rand() % ���κ�;

	//�� �Ѿ� ��Ÿ����
	//����: ���ڱ� active ���� ����

	for (i = 0; i < ENEMY_MAX; i++) {
		for (j = 0; j < ENEMY_MAX; j++) {
			if (g_firstMakeCheck <= ENEMY_MAX*ENEMY_MAX) {//ó������°Ÿ�
				//���ܹ߻�
				(*skill)[i][j].x = iR + i;//0~28���� ¦��//��� ������(18������)
				(*skill)[i][j].y = jR + j;
				(*skill)[i][j].power = 10;
				(*skill)[i][j].active = 1;
				g_firstMakeCheck++;
				break;//�� �����ӿ� �� ������ �����
			}
			if ((*skill)[i][j].active ==0) {//���� �� ������ֱ�
				(*skill)[i][j].x = iR+i;//0~28���� ¦��//��� ������(18������)
				(*skill)[i][j].y = jR+j;
				(*skill)[i][j].active = 1;
				break;//�� �����ӿ� �� ������ �����
			}
		}
	}
}

void printEnemySkill(Player* p, Bullet*** skill) {
	int i,j;
	for (i = 0; i < ENEMY_MAX; i++) {
		for (j = 0; j < ENEMY_MAX; j++) {
			if ((*skill)[i][j].active) {

				//�浹����
				if (g_second > 1)//�浹������ ��� �Ŀ�
				{
					if (((*skill)[i][j].x - 1 <= (*p).x && (*skill)[i][j].x + 1 >= (*p).x) && ((*skill)[i][j].y == (*p).y)) {
						(*p).hp -= (*skill)[i][j].power;//�÷��̾� �� ��´�.
						gotoXY((*p).x - 1, (*p).y - 1);
						setColor(0, 4);
						printf("ouch!!!");
					}
				}
				

				setColor(0, 3);
				//��ȿ���� �� ������ ���
				if (!((*skill)[i][j].y < ���κ�&& (*skill)[i][j].x < ���κ�)) {
					if (g_second <= 1) {
						gotoXY((*skill)[i][j].x, (*skill)[i][j].y);
						if ((int)(g_second * 10) % 2 == 0)
							printf("!");
					}
					else if(g_second <= 3 && g_second>1) {
						gotoXY((*skill)[i][j].x, (*skill)[i][j].y);
						printf("��");
					}
					else {
						(*skill)[i][j].active = 0;
						g_second = 0;
					}
				}
			}
		}
	}
}


void showEnemy(Enemy *e) {
	(*e).x = 7;
	(*e).y = 0;
	(*e).hp = 5000;//�ʱ� ��: 5000
	(*e).active = 1;
}


void showEnemyBullet(Enemy* e) {
	int i;
	//�� �Ѿ� ��Ÿ����
	for (i = 0; i < g_enemy_max; i++) {
		if (!(*e).bullet[i].active) {//���� �� ������ֱ�
			(*e).bullet[i].x = rand() % (���κ� / 2) * 2;
			(*e).bullet[i].y = 4;
			(*e).bullet[i].active = 1;
			break;//�� �����ӿ� �� ������ �����
		}
	}
}

void movePlayer(Player* p) {
	//Ű �Է¹ޱ�(�÷��̾��̵�)
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		(*p).y--;
		if ((*p).y < ���α���/2) (*p).y = ���α���/2;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		(*p).y++;
		if ((*p).y > ���κ�) (*p).y = ���κ�;//-1: Ŀ�� ��ġ������(������ Ŀ���� ������ġ�� ���ϱ�)
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)//VK: Ű������ �����, &������: Ű�� ���ȴ��� Ȯ��(8: ����-> ���ȴٸ� ��)
	{
		(*p).x--;
		if ((*p).x < 0) (*p).x = 0;//��
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)//VK: Ű������ �����, &������: Ű�� ���ȴ��� Ȯ��(8: ����-> ���ȴٸ� ��)
	{
		(*p).x++;
		if ((*p).x > ���κ�) (*p).x = ���κ�;//-2(�����϶�): Ŀ�� ��ġ������(������ Ŀ���� ������ġ�� ���ϱ�)
		//-1(�׸��϶�)
	}
}

void shoot(Player* p, Enemy *e) {
	int i, j;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)//VK: Ű������ �����, &������: Ű�� ���ȴ��� Ȯ��(8: ����-> ���ȴٸ� ��)
	{
		for (i = 0; i < PLAYER_MAX; i++) {
			if (!(((*p).bullet)[i].active)) {//�Ѿ� ���� ���� �Ѿ� Ȱ��ȭ
				((*p).bullet)[i].x = (*p).x;//�ʱⰪ
				((*p).bullet)[i].y = (*p).y - 1;
				((*p).bullet)[i].active = 1;
				break;
			}
		}
	}

	for (i = 0; i < PLAYER_MAX; i++) {
		if (((*p).bullet)[i].active) {//Ʈ���� ���ȿ���
			//�浹���� (�� ��ġ���� �Ѿ˰� �� ���� ��������)
			// : x������ ����
			// Ư������: 2����Ʈ
			for (j = 0; j < g_enemy_max; j++) {
				if (((*e).bullet[j].x - 2 <= ((*p).bullet)[i].x && (*e).bullet[j].x + 2 >= ((*p).bullet)[i].x) && ((*e).bullet[j].y - 2 <= ((*p).bullet)[i].y && (*e).bullet[j].y >= ((*p).bullet)[i].y) && (*e).bullet[j].active) {
					(*p).score += 10;//������ �ø���
					gotoXY(((*p).bullet)[i].x, ((*p).bullet)[i].y - 1);
					setColor(0, 14);
					printf("hit!!!");
					//�Ѿ��̶� ���� ���־��Ѵ�.
					(*e).bullet[j].active = 0;
					((*p).bullet)[i].active = 0;
				}
			}
			//�浹����(�� ��ġ���� ���̶� �Ѿ� ���� ��ġ��)
			{
				if (((*p).bullet[i].y >= 0 && (*p).bullet[i].y <= 3) && ((*e).x - 4 <= (*p).bullet[i].x && (*e).x + 15 >= (*p).bullet[i].x)) {
					(*e).hp -= (*p).bullet[i].power;
					if ((*e).hp <= 2000) {
						g_enemy_max = ENEMY_MAX + 10;
					}
					if ((*e).hp == 0) {
						(*p).score += 1000000;//�鸸���߰�
					}
					else
						(*p).score += 100;//������ �ø���
					gotoXY(((*p).bullet)[i].x+2, ((*p).bullet)[i].y );
					setColor(0, 12);
					printf("!!!");
				}
			}
			gotoXY(((*p).bullet)[i].x, ((*p).bullet)[i].y);
			setColor(0, 13);
			printf("��");
			((*p).bullet)[i].y--;
			if (((*p).bullet)[i].y == 0)
				((*p).bullet)[i].active = 0;
		}
	}
}


void printEnemy(Enemy* e) {
	int i;
	if ((*e).active) {
		if ((*e).hp <= 3500&& (*e).hp>=2000) {
			setColor(0, 8);
			gotoXY((*e).x, (*e).y);
			printf("����//����||����\n");
			gotoXY((*e).x - 5, (*e).y + 1);
			printf("  ��������������������\n");
			gotoXY((*e).x - 4, (*e).y + 2);
			printf("     @�����������");
		}
		else if ((*e).hp <= 2000) {
			setColor(0, 8);
			gotoXY((*e).x, (*e).y);
			printf("�����٣����ף���\n");
			gotoXY((*e).x - 5, (*e).y + 1);
			printf("  ��������������������\n");
			gotoXY((*e).x - 4, (*e).y + 2);
			printf("     @�����������");
			for (i = 0; i < g_enemy_max; i++) {
				(*e).bullet[i].power = 20;
			}
			

		}
		else
		{
			setColor(0, 8);
			gotoXY((*e).x, (*e).y);
			printf("�����ˣ����ˣ���\n");
			gotoXY((*e).x - 5, (*e).y + 1);
			printf("  ��������������������\n");
			gotoXY((*e).x - 4, (*e).y + 2);
			printf("     @�����������");
		}
		if ((*e).hp <= 2000) {
			(*e).x += 2 * g_enemyDirection;//�����̵�
			if ((*e).x + 15 >= ���κ� || (*e).x < 6) {//���� �ε�����
				g_enemyDirection *= -1;
			}
		}
		else {
			(*e).x += g_enemyDirection;//�����̵�
			if ((*e).x + 15 >= ���κ� || (*e).x < 6) {//���� �ε�����
				g_enemyDirection *= -1;
			}
		}

	}
}
void printEnemyBullet(Player* p, Enemy e) {
	int i;
	for (i = 0; i < g_enemy_max; i++) {
		if (e.bullet[i].active) {		
			//�浹����(�� ��ġ���� ���̶� �÷��̾�� ��ġ ��������)
			// Ŀ��+1�� Ŀ��-1�� ����(������ ���̴ϱ�)
			if (((e.bullet[i].x - 1 <= (*p).x && e.bullet[i].x + 1 >= (*p).x)) && (e.bullet[i].y - 1 <= (*p).y&& e.bullet[i].y >= (*p).y)) {
				e.bullet[i].active = 0;//�� ���ְ�
				(*p).hp -= e.bullet[i].power;//�÷��̾� �� ��´�.
				gotoXY((*p).x-1,(*p).y-1);
				setColor(0, 4);
				printf("ouch!!!");
			}
			setColor(0, 3);
			gotoXY(e.bullet[i].x, e.bullet[i].y);
			printf("��");
			e.bullet[i].y++;//�񳻷��´�
			if (e.bullet[i].y > ���α���) {
				e.bullet[i].active = 0;
			}
		}
	}
}

void makeWall() {
	int i;
	for (i = 0; i < ���α���; i++) {
		gotoXY(���κ� + 1, i);
		setColor(0, 15);
		printf("|");
	}
}

void printState(Player p,Enemy e) {
	int i;
	char c[] = "��";
	gotoXY(���κ� + 3, 0);
	printf("����: %d", p.score);
	gotoXY(���κ� + 3, 1);
	printf("��: ");
	for (i = 0; i < p.hp / 10; i++) {
		setColor(0, 12);
		printf("%s", c);
	}
	gotoXY(���κ� + 3, 2);
	setColor(0, 15);
	printf("�� ��: %d", e.hp);
	if (e.hp <= 2000) {
		gotoXY(���κ� + 3, 4);
		printf("������ ȭ�����! ");
		gotoXY(���κ� + 3, 5);
		printf("���� ������: 2�� ");
		gotoXY(���κ� + 3, 6);
		printf("�� ����: 2��");
	}
	else if ((e).hp <= 3500 && (e).hp >= 2000) {
		gotoXY(���κ� + 3, 4);
		printf("������ �ɱⰡ �����մϴ�..");
	}
}

void printPlayer(Player* p) {
	gotoXY((*p).x, (*p).y);
	setColor(0, 10);
	printf("��");
}



