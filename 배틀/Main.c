#pragma once//중복 방지+중복방지용 if then else가 필요함
#include "기본함수들.h"
#include <time.h>
#include "배틀함수.h"
#include "파일함수.h"
#include "씬.h"

//질문: 
//typedef써야만 main문에서 선언할 수 있는 이유 ?(그냥 struct했을 때 선언 안되더니
//typedef쓰니까 됨
//: typedef는 그 블록을 어떤 단어로 정의한다는 의미여서
//struct ~~로 쓰면 선언할 때 struct 붙여줘야 함.

//질문: 
//0. 기말고사 강의실 정해졌나요?: 수업 강의실 

float g_second;

int main() {
	
	int i = 0, j = 0;//인덱스용
	int r;
	
	int makeSkillFlag=0;

	//적	
	Enemy e = {0,0,NULL,0,10000};
	Bullet eb[ENEMY_MAX+20] = { 0,0,0,10 };
	for (i = 0; i < ENEMY_MAX; i++) {
		eb[i].power = 10;
	}
	
	//적 스킬
	Bullet **es = { 0};
	
	//플레이어	
	Player p = { 14,28,NULL,0,100 };
	//총알
	Bullet b[PLAYER_MAX] = { 0 };
	for (i = 0; i < PLAYER_MAX; i++) {
		b[i].power = 10;
	}

	//스킬 적에게 쥐여주기
	e.skill = &es;
	//총알 플레이어한테 쥐여주기
	p.bullet = &b;
	//총알 적에게 쥐여주기
	e.bullet = &eb;
	
	//랜덤시드
	srand(time(NULL));

	//콘솔창크기
	setConsoleSize(가로길이, 세로길이);

	//getch: 입력을 받을때까지 기다림->게임에는 적절치 않다.(블로킹)
	//kbhit: 값 있으면 내려주고 없으면 그냥 통과.(논블로킹)
	//GetAsyncKeyState: 어떤 키가 어떤 상태인지 값을 받아온다. 
	/*리턴값은
		0       :   전혀 안 눌려진 상황

		0x8000 : 호출 전 눌린적 없고 호출 시점에 눌린 상태

		0x8001 : 호출 전 눌려 있고 호출 시점에도 눌린 상태

		1 : 호출 전 눌린적 있고 호출 시점에는 안 눌린 상태
	*/

	showEnemy(&e);
	
	//시작화면
	시작화면();

	while (1) {//와일 문을 한 프레임이라고 생각하자
		clear();//잔상 지우기(전에 찍혔던 거). 프레임마다 새롭게 찍혀야하니까
		setInvisibleCursor();//커서 안 보이게
		
		//적 나타내기
		showEnemyBullet(&e);

		//키 입력받기(플레이어이동)
		movePlayer(&p);

		//키 입력받기(총알발사)
		//스페이스 누르면 총알 발사
		shoot(&p, &e);

		//적 프린트
		printEnemy(&e);
		printEnemyBullet(&p, e);

		//벽 만들기
		makeWall();

		//점수 출력
		printState(p,e);

		//플레이어 출력
		printPlayer(&p);

		//스킬 출력
		//예외생겨서중단
		//r = rand() %10;
		//
		//if (e.hp <= 2000&&r==0) {
		//	if (makeSkillFlag == 0) {
		//		makeSkill(&es);
		//		makeSkillFlag = 1;//한번 만들어지곤 안 만들어진다.
		//	}
		//	else
		//	{
		//		showEnemySkill(&e.skill);
		//		printEnemySkill(& p, &e.skill);
		//	}
		//}
		

		Sleep(100);//눈에 보일 수 있게 속도조절(프레임속도)
		//죽으면
		if (p.hp <= 0) {
			break;//반복문탈출
		}
		else if (e.hp <= 0) {//구름 죽이면
			break;//반복문 탈출
		}
	}

	//엔딩
	엔딩(&e, &p);
	
	return 0;
}