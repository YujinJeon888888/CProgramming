#pragma once
#include <windows.h>
#include <malloc.h>
#include <time.h>

//��������
#define ENEMY_MAX 10//�� �Ѿ˰���
#define PLAYER_MAX 3//�Ѿ˰���
#define ���α��� 80
#define ���α��� 30
#define ���κ� 50
//�ڵ�����
#define ���κ� (���α���-1)

//typedef struct {
//	int active;
//	char** skill;
//	int damage;
//}Skill;

typedef struct Enemy {//����: typedef��߸� main������ ������ �� �ִ� ����? 
	int x;
	int y;
	struct Bullet* bullet;
	struct Bullet* skill;
	int active;
	int hp;
}Enemy;

typedef struct Player {//typedef �̸�: �� ����� �̸����� �����Ѵٴ� ��. , struct �ϸ� struct���� ���ֱ�
	int x, y;
	struct Bullet* bullet;
	int score;
	int hp;
}Player;

typedef struct Bullet {
	int x, y;
	int active;
	int power;
}Bullet;

void printEnemy(Enemy* e);

void showEnemy(Enemy* e);

void showEnemyBullet(Enemy* e);

void movePlayer(Player* p);

void shoot(Player* p, Enemy *e);

void printEnemyBullet(Player* p, Enemy e);

void makeWall();

void printState(Player p, Enemy e);

void printPlayer(Player* p);

void makeSkill(Bullet*** skill);

void showEnemySkill(Bullet*** skill);

void printEnemySkill(Player* p, Bullet*** skill);