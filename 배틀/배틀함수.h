#pragma once
#include <windows.h>
#include <malloc.h>
#include <time.h>

//직접세팅
#define ENEMY_MAX 10//적 총알갯수
#define PLAYER_MAX 3//총알갯수
#define 가로길이 80
#define 세로길이 30
#define 가로벽 50
//자동세팅
#define 세로벽 (세로길이-1)

//typedef struct {
//	int active;
//	char** skill;
//	int damage;
//}Skill;

typedef struct Enemy {//질문: typedef써야만 main문에서 선언할 수 있는 이유? 
	int x;
	int y;
	struct Bullet* bullet;
	struct Bullet* skill;
	int active;
	int hp;
}Enemy;

typedef struct Player {//typedef 이름: 앞 블록을 이름으로 정의한다는 뜻. , struct 하면 struct까지 써주기
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