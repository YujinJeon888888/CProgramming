#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define ROW_MAX 10
#define COL_MAX 20

//빌딩의 층수를 저장해두는 전역변수
int FLOORS = 0;

void showMenu() {
	printf("----------------------------------------------------------------------------------------------------------------------------------------------- \n");
	printf("   1.빌딩보기   2.빌딩세우기(층)   3.층별 방만들기   4.입주시키기   5.층별보기   6.빌딩없애기  *7.층크기 변경하기  *8.방크기 변경하기 0.종료하기 \n");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------- \n");
}

void showBuilding(char*** bld, char* name) { //name은 건물이름

	int i, j, k; //i는 층, j는 층별방수


	//맨처음
	if (bld == NULL) {
		printf(" \n 건물이 지어지지 않았습니다. \n\n");
		return;
	}

	//층반복, 열반복으로 반복중첩문
	for (i = 0; i < FLOORS; i++) {//건물 층만큼

		k = FLOORS - i; //변수를 사용하거나 
		printf("%10s빌딩 [%d] : ", name, FLOORS - i);

		//i층에 할당된 방이 없는 경우		
		if (bld[i] == NULL) {
			printf("room 없음 \n");
			continue;
		}

		for (j = 0; j < _msize(bld[i]) / sizeof(char*); j++) {//층별 방수 만큼 
			//입주자 있으면 ■, 없으면 □
			if (bld[i][j] == NULL) printf("□");
			else printf("■");
		}
		printf("\n");
	}
}


//메인에서 building의 포인터를 받으려면 char ****bld로 받고 리턴값전달은 성공,실패 signal를 전달한다.  
char*** makeFloor(char*** bld) {
	int floor;

	if (bld != NULL) {
		printf("이미 건물의 층은 완성되었습니다. 층별 방을 만들 차례입니다. \n");
		return bld;
	}

	printf(" \n빌딩을 몇 층으로 만들까요? ");
	scanf("%d", &floor);

	//동적할당 예외처리(적정크기여야 동적할당 가능)
	if (floor <= 0 || floor > ROW_MAX) {
		printf("유효한 크기가 아닙니다. \n");
		return NULL;
	}

	//동적할당하고
	bld = (char***)malloc(floor * sizeof(char*));
	//동적할당된 공간을 초기화한다-> memset(포인터변수,초기할당값,크기)
	memset(bld, 0x0, floor * sizeof(char*)); //0x0은 16진수(알파벳 O와 구분하기 위해) 0->NULL로 써도 됨
	//전역변수 FLOORS에 층크기 저장, FLOORS = floor도 가능
	FLOORS = _msize(bld) / sizeof(char*); //계산식 대신 floor사용가능

	printf("\n %d 층의 빌딩이 만들어졌습니다. \n\n", FLOORS);

	return bld; //호출한 공간에 bld전달

}
//메인에서  building의 층정보가 필요하여 char **bld이
void makeRoom(char*** bld) {
	int floor, room, k;

	if (bld == NULL || FLOORS <= 0) {
		printf("빌딩을 먼저 만들어주세요. \n");
		return;
	}

	printf("방을 만들 층을 선택해주세요.: ");
	scanf("%d", &floor);

	k = FLOORS - floor;
	printf("k-> %d \n", k);   //인덱스 확인용 출력

	if (bld[k] != NULL || floor > FLOORS || floor <= 0) {
		printf("해당 층이 존재하지 않거나 이미 방이 만들어져있습니다. \n");
		return;
	}

	printf("[%d] 층에 만들 방의 개수를 선택해주세요. : ", floor);
	scanf("%d", &room);

	if (room <= 0 || room > COL_MAX) {
		printf("유효한 크기가 아닙니다. \n");
		return;
	}
	bld[k] = (char**)malloc(room * sizeof(char*));
	memset(bld[k], 0x0, room * sizeof(char*));
	printf("[%d] 층에 %d개의 방을 만들었습니다. \n", floor, room);
}

void moveIn(char*** bld) {
	int floor, room, k, i;
	char c;

	if (bld == NULL || FLOORS <= 0) {
		printf("빌딩을 먼저 만들어주세요. \n");
		return;
	}
	printf("입주할 층과 방번호를 올바로 입력해주세요:");
	scanf("%d %d", &floor, &room);
	scanf("%c", &c);

	k = FLOORS - floor;
	i = room - 1;

	//유효한가?
	if (k >= FLOORS || bld[k] == NULL || i >= _msize(bld[k]) / sizeof(char*)) {
		printf("해당 공간은 유효하지 않습니다. 방을 생성하거나 올바른 번호를 입력해주세요. \n");
		return;
	}

	//이미 누군가 살고있는 공간인가?
	if (bld[k][i] != NULL) {
		printf("이미 다른 사람이 입주해 있습니다. \n"); //새로 입주받을지, 유지할지 선택가능. 
		return;
	}

	bld[k][i] = (char*)malloc(sizeof(char) * 100);
	printf("입주자 이름을 입력하세요 : ");
	gets(bld[k][i]);
	bld[k][i] = (char*)realloc(bld[k][i], strlen(bld[k][i]) + 1);
}

void showFloor(char*** bld) {
	int i, f, room, k;

	if (bld == NULL) {
		printf("빌딩이 지어지지 않았습니다. \n");
		return;
	}

	printf("몇 층의 정보를 볼까요? ");
	scanf("%d", &f);

	k = FLOORS - f;

	if (bld[k] == NULL || f > FLOORS) {
		printf("해당 층이 없거나 해당 층에 만들어진 방이 없습니다. \n");
		return;
	}

	room = _msize(bld[k]) / sizeof(char*);  //32비트에서는 4, 64비트에서는 8. 

	for (i = 0; i < room; i++) {
		printf("room[%d] : ", i + 1);
		if (bld[k][i] == NULL) printf("□ : -- \n");
		else printf("■ : %s \n", bld[k][i]);
	}
	printf("\n");
}

int main() {

	char*** building = NULL; // ***인 이유 2차원배열의 층(1),열(2) 지정하고  그 안의 문자열(3)까지 가야하기 때문
	int menu, floor = 0, room;
	char name[10];
	char YorN;

	int i, k;

	printf("이화건축사무소에 오신 걸 환영합니다! \n\n\n");
	printf("빌딩의 이름을 정해주세요(10자 이내) : ");
	//scanf("%s", name); //배열이므로 &사용 안 함 , 띄어쓰기 사용못함
	gets(name); //띄어쓰기 가능
	printf("\n '%s'빌딩의 건축을 시작하겠습니다. \n\n", name);

	while (1) {
		showMenu();
		printf("menu: ");
		scanf("%d", &menu);

		//if 대신switch문 사용도 가능 & menu 6기능 만들기
		if (menu == 0) {
			printf("건물 건축을 종료합니다. 이화건축사무소을 이용해주셔서 감사합니다! \n");
			break;
		}

		if (menu == 1) showBuilding(building, name);
		else if (menu == 2) building = makeFloor(building);
		//리턴값이 없는 형태로 만드려면 &building을 전달한다.   makeFloor(&building);  

		else if (menu == 3) makeRoom(building);
		else if (menu == 4) moveIn(building);
		else if (menu == 5) showFloor(building);
		else if (menu == 6) {
			//이 부분을 완성하여 함수로 만들어 봅니다. 
			//destroyBuilding(&building);

	  ///////////////////////////////////////////////////////
			printf("빌딩을 없애시겠습니까?(Y/N) ");
			scanf("%c", &YorN);

			while (YorN != 'Y' && YorN != 'N') {
				printf("Y / N 으로 질문에 답해주세요. : ");
				scanf("%c", &YorN);
			}

			if (YorN == 'Y') {

				//가장 안쪽공간부터 반납합니다.  방->층->건물순으로 free하세요.
					  //열공간에 할당받은 곳을 free하지 않고 층공간을 없아면, 열공간은 garbage가 됩니다.-> 메모리 누수!
				for (i = 0; i < FLOORS; i++) {
					free(building[i]);
					building[i] = NULL;
				}
				free(building);
				building = NULL;

				printf("빌딩을 무너뜨렸습니다.\n");
				FLOORS = 0;
			}

			else 	printf("빌딩 없애기를 취소하셨습니다. \n");

		}
	}
	return 0;

}