#include <stdio.h>



struct 수강과목정보
{
	char title[50];
	char prof[30];
	int score;
};

struct 생일
{
	int year;
	int month;
	int day;
};

typedef struct 학생
{
	char 학과[50];
	int  학번;
	int 학년;
    char 이름[10];
	struct 생일 birth;
	int 수강과목개수;
	struct 수강과목정보 sbjInfo;
}STD;

void 출력하기(STD s[], int n) {


    int i;

    printf("----------------------------------------------------------------------------\n");
    printf(" No.        학과           학번        학년    이름  \n");
    printf("----------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%d", i + 1);
        printf("%20s  %d        %3d    %5s \n", s[i].학과, s[i].학번, s[i].학년, s[i].이름);
    }

    printf("----------------------------------------------------------------------------\n");
    printf("         출생년도          출생월        출생일    수강과목수  \n");
    printf("----------------------------------------------------------------------------\n");
    //막히는 부분: 
    //구조체를 멤버로 갖는 구조체
    for (i = 0; i < n; i++) {
        printf("%4d       %2d        %2d    %5d \n", s[i].birth.year, s[i].birth.month, s[i].birth.day, s[i].수강과목개수);
    }

    printf("----------------------------------------------------------------------------\n");
    printf("         과목           교수        점수    \n");
    printf("----------------------------------------------------------------------------\n");
    //막히는 부분: 
   //구조체를 멤버로 갖는 구조체
    for (i = 0; i < n; i++) {
        printf("%20s  %10d        %3d    \n", s[i].sbjInfo, s[i].학번, s[i].학년);
    }


    printf("----------------------------------------------------------------------------\n");

}
void 성적읽기(char* filename, STD s[], int* n) {
    FILE* fp = NULL;//널로 초기화
    fp = fopen(filename, "r");//파일 네임으로 오픈한다, r: read용이다. 
    char name[100] = "";
    int i = 0;


    if (fp == NULL) {//못 읽으면 null리턴
        printf("화일읽기 실패 프로그램을 종료합니다. \n");
        exit(1);
    }
    printf("학생 수를 입력하세요 ^^:");
    scanf("%d", n);//&안붙이는 이유: 포인터변수니까 

    while (1) {
        //화일의 끝에 도달하면 0이 아닌 값을 리턴함.        
        if (feof(fp) != 0)  break;//끝에 도달했다->반복문 끝낸다. 
        if (i == *n) break;//학생 수까지만 읽는다. 
        fscanf(fp, "%s", s[i].학과);
        fscanf(fp, "%d", &s[i].학번);
        fscanf(fp, "%d", &s[i].학년);
        fscanf(fp, "%s", s[i].이름);

        //막히는 부분: 생일정보 저장(생일정보 :구조체)
        fscanf(fp, "%d", &s[i].birth.year);
        fscanf(fp, "%d", &s[i].birth.month);
        fscanf(fp, "%d", &s[i].birth.day);

        //수강과목수
        fscanf(fp, "%d", &s[i].수강과목개수);

        //과목정보
        fscanf(fp, "%s", s[i].sbjInfo.title);
        fscanf(fp, "%s", s[i].sbjInfo.prof);
        fscanf(fp, "%d", &s[i].sbjInfo.score);


      
        
        i++;
    }

    //화일을 모두 읽었는데 학생 수보다 적다면 다시 저장
    if (i < *n) {
        printf("화일에서 읽어온 학생 수로 변경합니다.! \n");
        *n = i;//n의 값을 바꾼다. *붙인 이유
    }
}

void showMenu() {
    printf("===================================\n");
    printf("1. 성적읽기 2. 출력하기 0. 종료\n");
    printf("===================================\n");
}

int main() {
	STD s[100] = { 0 };
	int i, numOfStd;//학생수
    int menu;
    char 화일이름[100] = "학생정보.txt";

    while (1) {
        showMenu();
        printf("메뉴를 입력하세요 : ");
        scanf("%d", &menu);

        if (menu == 0) break;
        if (menu == 1) {
            성적읽기(화일이름, s, &numOfStd);
        }
        if (menu == 2) 출력하기( s, &numOfStd);
      

        printf("\n");
    }

    printf("학사정보 시스템을 종료합니다.");
	
	return 0;
}