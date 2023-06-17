//#include <stdio.h>
//#include <malloc.h>
//#include <ctype.h>
//#include <time.h>
//#include <Windows.h>
//
//#define MAX 10
//#define MIN 0
//
//void intro() {
//
//	printf("    A____________________________A \n");
//	printf("    |        º     ㅅ    º     | \n");
//	printf("    |　                          | \n");
//	printf("    |　　　　　　　　　　　      |  \n");
//	printf("    |　행복해? 힘들어? 배고파?   |  \n");
//	printf("    ￣U￣￣￣￣￣￣￣￣￣￣￣￣U￣  \n");
//	//setcolor(11, 0);
//}
//
//void showMenu() {
//
//	printf("\n");
//	printf("---------------------------------------------------------------------------------------\n");
//	printf(" 1.음악듣기  2.잠자기  3.놀기  4.공부하기 ...8.상태보기  9. 상태체크하기 0.종료 \n");
//	printf("---------------------------------------------------------------------------------------\n");
//
//	printf("\n");
//}
//
//void showValue(int value, char* name) {
//	int i;
//
//	printf("%10s(%2d)", name, value);
//	for (i = 0; i < value; i++) {//값을 하트갯수로 표시
//		printf("♡");
//	}
//	printf("\n");
//}
//
//
//void showStatus(int happy, int stress, int tired, int hungry, int kp, int hp) {
//	printf("-------------------------------------------------\n");
//	showValue(happy, "행복감");
//	showValue(stress, "스트레스");
//	showValue(tired, "피로도");
//	showValue(hungry, "배고픔");
//	showValue(kp, "지력");
//	showValue(hp, "체력");
//	printf("-------------------------------------------------\n");
//}
//
//void checkStatus(int happy, int stress, int tired, int hungry, int kp, int hp) {
//
//	//나의 상태를 점검해봅니다.
//	printf("\n **  행복회로의 제안 메시지 ** \n");
//	//1.배고프면 안되죠?
//	if (hungry < 3) {
//		printf("배가 고픈 상태에서는 휴식도 일도 무리입니다.! \n");
//		//예) 먹기()함수를 강제로 호출해보세요
//	}
//
//	//2.지력은 높으나 스트레스가 높고 체력이 낮을 때 ==> 휴식
//	if (kp >= 5 && hp < 5 && stress >= 5) {
//		printf("열심히 공부하느라 힘들었죠?  심신안정을 위해 음악을 듣거나 운동을 해보는 것이 좋겠습니다! \n");
//		//예) 잠자기()나 음악듣기() 같은 쉬는 동작을 호출합니다.
//	}
//
//	//3.심신이 안정되었을 경우에는  운동이나 공부
//	if (happy >= 5 && tired < 5 && stress < 5) {
//		printf("심신이 안정되었으니 이제 열심히 달려볼까요? 운동해서 체력을 기르거나 공부를 해도 좋겠습니다.! \n");
//		//예) 운동하기()나 공부하기()처럼  일하기 동작을 호출하세요
//		// 
//	}
//	//기타 추가해보세요
//	printf("오늘도 좋은 하루 !\n");
//	printf("~~~~\n");
//
//}
//
/////////////////////////////////
//
//void 음악듣기(int* happy, int* stress, int* tired, int* hungry, int* kp, int* hp) {
//	//행복감 +2,   스트레스 -2 , 
//	//test
//
//	*happy += 2;
//	*stress -= 2;
//
//	printf("음악을 듣습니다 \n");
//	printf("기분이 조금 나아졌어요 ! \n");
//}
//
//void 잠자기(int* happy, int* stress, int* tired, int* hungry, int* kp, int* hp) {
//	//스트레스 -2, 피로도 -5, 체력 +2, 배고픔 +2;
//
//	*stress -= 2;
//	*tired -= 5;
//	*hp += 2;
//	*hungry += 2;
//
//	printf("잠을 잠니다..쿨쿨쿨 \n");
//	printf("기분도 좋아지고 개운해 졌는데 배가 고파졌어요! 꼬르륵.. \n");
//}
//
//
//void 공부하기(int* happy, int* stress, int* tired, int* hungry, int* kp, int* hp) {
//
//	printf("공부하기! \n");
//
//	*happy += 1;
//	*stress += 3;
//	*tired += 2;
//	*kp += 2;
//}
//
//
//
//void 놀기(int* happy, int* stress, int* tired, int* hungry, int* kp, int* hp) {
//	printf("룰루랄라@!#$%^ 놀때는 즐겁게!! \n");
//
//	*happy += 1;
//	*stress += 3;
//	*tired += 2;
//	*kp += 2;
//
//}
//
//void delay(int second) {
//	int i = 0;
//	printf("-------------------------------------------------\n");
//	printf("check 중 : ");
//	for (i = 0; i < second * 2; i++) {
//		printf(" * ");
//		Sleep(500);   //0.5초쉬기 //Windows.h라이브러리
//	}
//}
//int main() {
//	//감정변수들 : 1~10 ,  초기값은 자유.
//	int 행복감, 스트레스, 피로도, 배고픔, 지력, 체력;
//	int menu;
//	//함수포인터
//	void(*fp[5])(int*, int*, int*, int*, int*, int*) = { NULL, 음악듣기, 놀기,잠자기, 공부하기 };
//
//	//초기화    
//	행복감 = 스트레스 = 피로도 = 배고픔 = 지력 = 체력 = 1;
//	배고픔 = 5;
//	intro();
//	while (1) {
//
//		showMenu();
//		printf("menu : "); scanf("%d", &menu);
//		if (menu == 0) break;
//
//		//함수포인터를 사용하면,  동작메뉴일 경우 아래처럼 간단히 호출시킬 수 있음.
//		if(menu>=1&&menu<=4)
//			fp[menu](&행복감, &스트레스, &피로도, &배고픔, &지력, &체력);
//
//		/*if (menu == 1)  음악듣기(&행복감, &스트레스, &피로도, &배고픔, &지력, &체력);
//		if (menu == 2)  잠자기(&행복감, &스트레스, &피로도, &배고픔, &지력, &체력);
//		if (menu == 3)  놀기(&행복감, &스트레스, &피로도, &배고픔, &지력, &체력);
//		if (menu == 4)  공부하기(&행복감, &스트레스, &피로도, &배고픔, &지력, &체력);*/
//		
//		// 기능 추가
//		//
//
//		if (menu == 8)  showStatus(행복감, 스트레스, 피로도, 배고픔, 지력, 체력);
//		if (menu == 9) checkStatus(행복감, 스트레스, 피로도, 배고픔, 지력, 체력);
//
//		//매 회마다 자동호출도록 넣어봤어요
//		showStatus(행복감, 스트레스, 피로도, 배고픔, 지력, 체력);
//
//		//3초쉬고 제안메시지 보기
//		delay(3);
//
//		checkStatus(행복감, 스트레스, 피로도, 배고픔, 지력, 체력);
//	}
//	return 0;
//}