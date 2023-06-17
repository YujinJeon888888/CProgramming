#include "씬.h"

void 엔딩(Enemy *e,Player *p) {
	int i;
	char ID[20] = "";
	system("cls");
	gotoXY(0, 0);
	setColor(0, 14);
	for (i = 0; i < 가로길이 / 2; i++) {
		printf("★");
	}
	gotoXY(0, 세로길이 - 1);
	for (i = 0; i < 가로길이 / 2; i++) {
		printf("★");
	}
	if ((*e).hp <= 0) {
		gotoXY((가로길이 / 2) - 14, 0);
		setColor(0, 15);
		printf("구름을 죽였어요. 야호!!\n\n\n");
		printf("아이디를 입력하세요: ");
	}
	else {
		gotoXY((가로길이 / 2) - 4, 0);
		setColor(0, 15);
		printf("죽었어용\n\n\n");
		printf("아이디를 입력하세요: ");
	}
	//질문: 함수색이 이상해요: _s안해서.  
	gets_s(ID, 20);//아이디에 저장
	점수파일열기(&(*p), ID);//질문: include안했는데 돌아가고, include하면 오류난다.: paragma once
	
	system("pause");
}

void 시작화면() {
	int i;
	char answer=0;
	char buffer[20] = "";
	system("cls");
	while (1) {
		gotoXY(0, 0);
		setColor(0, 14);
		for (i = 0; i < 가로길이 / 2; i++) {
			printf("★");
		}
		gotoXY(0, 세로길이 - 1);
		for (i = 0; i < 가로길이 / 2; i++) {
			printf("★");
		}


		gotoXY((가로길이 / 2) - 10, 0);
		setColor(0, 15);
		printf("구름 vs 플레이어\n\n\n");

		setColor(0, 3);
		gotoXY(가로길이 / 2 - 12, 6);
		printf("＠＠Λ＠＠Λ＠＠\n");
		gotoXY((가로길이 / 2 - 12) - 5, 6 + 1);
		printf("  ＠＠＠⊙＠＠⊙＠＠＠\t\t");
		setColor(0, 14);
		printf("『안뇽♬』\n");
		setColor(0, 3);
		gotoXY((가로길이 / 2 - 12) - 4, 6 + 2);
		printf("     @＠＠▼＠＠＠\n\n\n\n\n");


		setColor(0,2);
		printf("\t\t\t시작하려면 스페이스키를 입력하세요: ");
		scanf("%c", &answer);
		if (answer==' ') {
			gets_s(buffer, 20);//버퍼먹기
			return;
		}
		else {
			system("cls");
			gets_s(buffer, 20);//버퍼먹기
			continue;
		}
	}
}