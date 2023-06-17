#include "배틀함수.h"
#include "기본함수들.h"

extern float g_second;
int g_firstMakeCheck=0;
int g_enemy_max = ENEMY_MAX;
int g_enemyDirection = 1;

void makeSkill(Bullet*** skill) {//가로벽과 세로벽 범위내에서 레이저 쏘기
	int i,j;
	//왼쪽변수와 말록 타입 별 갯수 더해서 같아져야함(3개)
	*skill = (Bullet**)malloc(ENEMY_MAX * sizeof(Bullet*));//주소를 넘겨주는거니까 별2개
	//동적할당된 공간을 초기화한다-> memset(포인터변수,초기할당값,크기)
	memset(*skill, 0x0, ENEMY_MAX * sizeof(char*)); //0x0은 16진수(알파벳 O와 구분하기 위해) 0->NULL로 써도 됨
	for (i = 0; i < ENEMY_MAX; i++) {		
		(*skill)[i] = (Bullet*)malloc(ENEMY_MAX * sizeof(Bullet));
		memset((*skill)[i], 0x1, ENEMY_MAX * sizeof(Bullet)); //0x0은 16진수(알파벳 O와 구분하기 위해) 0->NULL로 써도 됨
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

	iR = rand() % 세로벽;
	jR = rand() % 가로벽;

	//적 총알 나타내기
	//예외: 갑자기 active 값이 변함

	for (i = 0; i < ENEMY_MAX; i++) {
		for (j = 0; j < ENEMY_MAX; j++) {
			if (g_firstMakeCheck <= ENEMY_MAX*ENEMY_MAX) {//처음만드는거면
				//예외발생
				(*skill)[i][j].x = iR + i;//0~28까지 짝수//잠깐 수정함(18까지로)
				(*skill)[i][j].y = jR + j;
				(*skill)[i][j].power = 10;
				(*skill)[i][j].active = 1;
				g_firstMakeCheck++;
				break;//한 프레임에 한 개씩만 만들기
			}
			if ((*skill)[i][j].active ==0) {//없을 때 만들어주기
				(*skill)[i][j].x = iR+i;//0~28까지 짝수//잠깐 수정함(18까지로)
				(*skill)[i][j].y = jR+j;
				(*skill)[i][j].active = 1;
				break;//한 프레임에 한 개씩만 만들기
			}
		}
	}
}

void printEnemySkill(Player* p, Bullet*** skill) {
	int i,j;
	for (i = 0; i < ENEMY_MAX; i++) {
		for (j = 0; j < ENEMY_MAX; j++) {
			if ((*skill)[i][j].active) {

				//충돌판정
				if (g_second > 1)//충돌판정은 경고 후에
				{
					if (((*skill)[i][j].x - 1 <= (*p).x && (*skill)[i][j].x + 1 >= (*p).x) && ((*skill)[i][j].y == (*p).y)) {
						(*p).hp -= (*skill)[i][j].power;//플레이어 피 깎는다.
						gotoXY((*p).x - 1, (*p).y - 1);
						setColor(0, 4);
						printf("ouch!!!");
					}
				}
				

				setColor(0, 3);
				//유효범위 내 까지만 찍기
				if (!((*skill)[i][j].y < 세로벽&& (*skill)[i][j].x < 가로벽)) {
					if (g_second <= 1) {
						gotoXY((*skill)[i][j].x, (*skill)[i][j].y);
						if ((int)(g_second * 10) % 2 == 0)
							printf("!");
					}
					else if(g_second <= 3 && g_second>1) {
						gotoXY((*skill)[i][j].x, (*skill)[i][j].y);
						printf("＃");
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
	(*e).hp = 5000;//초기 피: 5000
	(*e).active = 1;
}


void showEnemyBullet(Enemy* e) {
	int i;
	//적 총알 나타내기
	for (i = 0; i < g_enemy_max; i++) {
		if (!(*e).bullet[i].active) {//없을 때 만들어주기
			(*e).bullet[i].x = rand() % (가로벽 / 2) * 2;
			(*e).bullet[i].y = 4;
			(*e).bullet[i].active = 1;
			break;//한 프레임에 한 개씩만 만들기
		}
	}
}

void movePlayer(Player* p) {
	//키 입력받기(플레이어이동)
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		(*p).y--;
		if ((*p).y < 세로길이/2) (*p).y = 세로길이/2;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		(*p).y++;
		if ((*p).y > 세로벽) (*p).y = 세로벽;//-1: 커서 위치때문에(찍으면 커서는 다음위치로 가니까)
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)//VK: 키에대한 상수값, &연산자: 키가 눌렸는지 확인(8: 눌림-> 눌렸다면 참)
	{
		(*p).x--;
		if ((*p).x < 0) (*p).x = 0;//벽
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)//VK: 키에대한 상수값, &연산자: 키가 눌렸는지 확인(8: 눌림-> 눌렸다면 참)
	{
		(*p).x++;
		if ((*p).x > 가로벽) (*p).x = 가로벽;//-2(세모일때): 커서 위치때문에(찍으면 커서는 다음위치로 가니까)
		//-1(네모일때)
	}
}

void shoot(Player* p, Enemy *e) {
	int i, j;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)//VK: 키에대한 상수값, &연산자: 키가 눌렸는지 확인(8: 눌림-> 눌렸다면 참)
	{
		for (i = 0; i < PLAYER_MAX; i++) {
			if (!(((*p).bullet)[i].active)) {//총알 없을 때만 총알 활성화
				((*p).bullet)[i].x = (*p).x;//초기값
				((*p).bullet)[i].y = (*p).y - 1;
				((*p).bullet)[i].active = 1;
				break;
			}
		}
	}

	for (i = 0; i < PLAYER_MAX; i++) {
		if (((*p).bullet)[i].active) {//트루인 동안에만
			//충돌판정 (이 위치에서 총알과 적 범위 같아지면)
			// : x범위를 보자
			// 특수문자: 2바이트
			for (j = 0; j < g_enemy_max; j++) {
				if (((*e).bullet[j].x - 2 <= ((*p).bullet)[i].x && (*e).bullet[j].x + 2 >= ((*p).bullet)[i].x) && ((*e).bullet[j].y - 2 <= ((*p).bullet)[i].y && (*e).bullet[j].y >= ((*p).bullet)[i].y) && (*e).bullet[j].active) {
					(*p).score += 10;//점수도 올리고
					gotoXY(((*p).bullet)[i].x, ((*p).bullet)[i].y - 1);
					setColor(0, 14);
					printf("hit!!!");
					//총알이랑 적도 없애야한다.
					(*e).bullet[j].active = 0;
					((*p).bullet)[i].active = 0;
				}
			}
			//충돌판정(이 위치에서 적이랑 총알 범위 겹치면)
			{
				if (((*p).bullet[i].y >= 0 && (*p).bullet[i].y <= 3) && ((*e).x - 4 <= (*p).bullet[i].x && (*e).x + 15 >= (*p).bullet[i].x)) {
					(*e).hp -= (*p).bullet[i].power;
					if ((*e).hp <= 2000) {
						g_enemy_max = ENEMY_MAX + 10;
					}
					if ((*e).hp == 0) {
						(*p).score += 1000000;//백만점추가
					}
					else
						(*p).score += 100;//점수도 올리고
					gotoXY(((*p).bullet)[i].x+2, ((*p).bullet)[i].y );
					setColor(0, 12);
					printf("!!!");
				}
			}
			gotoXY(((*p).bullet)[i].x, ((*p).bullet)[i].y);
			setColor(0, 13);
			printf("♠");
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
			printf("＠＠//＠＠||＠＠\n");
			gotoXY((*e).x - 5, (*e).y + 1);
			printf("  ＠＠＠⊙＠＠⊙＠＠＠\n");
			gotoXY((*e).x - 4, (*e).y + 2);
			printf("     @＠＠▲＠＠＠");
		}
		else if ((*e).hp <= 2000) {
			setColor(0, 8);
			gotoXY((*e).x, (*e).y);
			printf("＠＠↘＠＠↙＠＠\n");
			gotoXY((*e).x - 5, (*e).y + 1);
			printf("  ＠＠＠⊙＠＠⊙＠＠＠\n");
			gotoXY((*e).x - 4, (*e).y + 2);
			printf("     @＠＠■＠＠＠");
			for (i = 0; i < g_enemy_max; i++) {
				(*e).bullet[i].power = 20;
			}
			

		}
		else
		{
			setColor(0, 8);
			gotoXY((*e).x, (*e).y);
			printf("＠＠Λ＠＠Λ＠＠\n");
			gotoXY((*e).x - 5, (*e).y + 1);
			printf("  ＠＠＠⊙＠＠⊙＠＠＠\n");
			gotoXY((*e).x - 4, (*e).y + 2);
			printf("     @＠＠▼＠＠＠");
		}
		if ((*e).hp <= 2000) {
			(*e).x += 2 * g_enemyDirection;//가로이동
			if ((*e).x + 15 >= 가로벽 || (*e).x < 6) {//벽에 부딪히면
				g_enemyDirection *= -1;
			}
		}
		else {
			(*e).x += g_enemyDirection;//가로이동
			if ((*e).x + 15 >= 가로벽 || (*e).x < 6) {//벽에 부딪히면
				g_enemyDirection *= -1;
			}
		}

	}
}
void printEnemyBullet(Player* p, Enemy e) {
	int i;
	for (i = 0; i < g_enemy_max; i++) {
		if (e.bullet[i].active) {		
			//충돌판정(이 위치에서 적이랑 플레이어랑 위치 같아지면)
			// 커서+1와 커서-1의 사이(찍히기 전이니까)
			if (((e.bullet[i].x - 1 <= (*p).x && e.bullet[i].x + 1 >= (*p).x)) && (e.bullet[i].y - 1 <= (*p).y&& e.bullet[i].y >= (*p).y)) {
				e.bullet[i].active = 0;//적 없애고
				(*p).hp -= e.bullet[i].power;//플레이어 피 깎는다.
				gotoXY((*p).x-1,(*p).y-1);
				setColor(0, 4);
				printf("ouch!!!");
			}
			setColor(0, 3);
			gotoXY(e.bullet[i].x, e.bullet[i].y);
			printf("§");
			e.bullet[i].y++;//비내려온다
			if (e.bullet[i].y > 세로길이) {
				e.bullet[i].active = 0;
			}
		}
	}
}

void makeWall() {
	int i;
	for (i = 0; i < 세로길이; i++) {
		gotoXY(가로벽 + 1, i);
		setColor(0, 15);
		printf("|");
	}
}

void printState(Player p,Enemy e) {
	int i;
	char c[] = "♥";
	gotoXY(가로벽 + 3, 0);
	printf("점수: %d", p.score);
	gotoXY(가로벽 + 3, 1);
	printf("피: ");
	for (i = 0; i < p.hp / 10; i++) {
		setColor(0, 12);
		printf("%s", c);
	}
	gotoXY(가로벽 + 3, 2);
	setColor(0, 15);
	printf("적 피: %d", e.hp);
	if (e.hp <= 2000) {
		gotoXY(가로벽 + 3, 4);
		printf("구름이 화났어요! ");
		gotoXY(가로벽 + 3, 5);
		printf("비의 데미지: 2배 ");
		gotoXY(가로벽 + 3, 6);
		printf("비 갯수: 2배");
	}
	else if ((e).hp <= 3500 && (e).hp >= 2000) {
		gotoXY(가로벽 + 3, 4);
		printf("구름의 심기가 불편합니다..");
	}
}

void printPlayer(Player* p) {
	gotoXY((*p).x, (*p).y);
	setColor(0, 10);
	printf("■");
}



