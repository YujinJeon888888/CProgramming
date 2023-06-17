#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  course {

    char title[50];
    char prof[50];
    int score;
    char grade[3]; // score 점수로 계산함 : A+, A0
} Course;

//성적화일을 읽었는지 나타내는 변수 . 읽었으면 1
flag = 0;

void showMenu() {
    printf("\n            짱구의 성적표 \n");
    printf("---------------------------------------------------------------------------------------------\n");
    printf("1.과목정보읽기 2.학점구하기 3.총점과 평균구하기 4.성적으로 정렬하기  5. 성적표보기  0.그만\n");
    printf("---------------------------------------------------------------------------------------------\n");
}
void 성적읽기_pointer(char* filename, Course** s, int* n) {
    FILE* fp = NULL;//널로 초기화
    fp = fopen(filename, "r");//파일 네임으로 오픈한다, r: read용이다. 
    char name[100] = "";
    int i = 0;

    if (fp == NULL) {//못 읽으면 null리턴
        printf("화일읽기 실패 프로그램을 종료합니다. \n");
        exit(1);
    }
    printf("과목개수를 입력하세요:");
    scanf("%d", n);//&안붙이는 이유: 포인터변수니까 



    //갯수여러개
    //이렇게 리턴받으면 배열처럼 쓸 수 있는건가요?=>O 배열처럼 씀
    *s = (Course*)malloc(sizeof(Course) * (*n));//주소리턴, n개만큼
    memset(*s, 0x0, sizeof(Course) * (*n));

    while (1) {
        //화일의 끝에 도달하면 0이 아닌 값을 리턴함.        
        if (feof(fp) != 0)  break;//끝에 도달했다->반복문 끝낸다. 
        if (i == *n) break;//과목 갯수까지만 읽는다. 
        //포인터로 선언했으니까(->할때와 .할때
        fscanf(fp, "%s", (*s)[i].title);//fp에서(인자 추가됨 fscanf여서), 타이틀 문자열 읽는다. 
        fscanf(fp, "%s", (*s)[i].prof);//s: 넘긴 포인터변수의 주소를 가짐. *s: 넘긴 포인터 변수의 값==넘긴 포인터변수에 *담긴* 주소. 
        fscanf(fp, "%d", &(*s)[i].score);//따라서 인덱스 사용-> 넘긴 포인터 변수가 가리키는 것들을 인덱스로 접근
        i++;
    }

    //화일을 모두 읽었는데 과목개수보다 적다면 다시 저장
    if (i < *n) {
        printf("화일에서 읽어온 과목개수로 변경합니다.! \n");
        *n = i;//n의 값을 바꾼다. *붙인 이유
    }
}

void 성적읽기(char* filename, Course s[], int* n) {
    FILE* fp = NULL;//널로 초기화
    fp = fopen(filename, "r");//파일 네임으로 오픈한다, r: read용이다. 
    char name[100] = "";
    int i = 0;


    if (fp == NULL) {//못 읽으면 null리턴
        printf("화일읽기 실패 프로그램을 종료합니다. \n");
        exit(1);
    }
    printf("과목개수를 입력하세요:");
    scanf("%d", n);//&안붙이는 이유: 포인터변수니까 

    while (1) {
        //화일의 끝에 도달하면 0이 아닌 값을 리턴함.        
        if (feof(fp) != 0)  break;//끝에 도달했다->반복문 끝낸다. 
        if (i == *n) break;//과목 갯수까지만 읽는다. 
        fscanf(fp, "%s", s[i].title);//fp에서(인자 추가됨 fscanf여서), 타이틀 문자열 읽는다. 
        fscanf(fp, "%s", s[i].prof);
        fscanf(fp, "%d", &s[i].score);
        i++;
    }

    //화일을 모두 읽었는데 과목개수보다 적다면 다시 저장
    if (i < *n) {
        printf("화일에서 읽어온 과목개수로 변경합니다.! \n");
        *n = i;//n의 값을 바꾼다. *붙인 이유
    }
}

void 학점구하기(Course s[], int n) {

    int i;


    for (i = 0; i < n; i++) {
        if (s[i].score >= 90) s[i].grade[0] = 'A';  //또는 strcpy(s[i].grade="A");
        else if (s[i].score >= 80) s[i].grade[0] = 'B';  //또는 strcpy(s[i].grade="B");
        else if (s[i].score >= 70) s[i].grade[0] = 'C';  //또는 strcpy(s[i].grade="C");
        else if (s[i].score >= 60) s[i].grade[0] = 'D';  //또는 strcpy(s[i].grade="C");
        else s[i].grade[0] = 'F';

        //+, 0 결정
        if (s[i].score >= 60) {//D부터만 +0 붙일 수 있으니까
            if (s[i].score == 100 || s[i].score % 10 >= 5) s[i].grade[1] = '+';
            else s[i].grade[1] = '0';
        }
    }
    printf("%d 과목의 성적으로 학점을 계산했습니다!\n\n", n);

}
//두개의 값을 저장해야 하므로 포인터로 전달받아 사용합니다.
void 총점_평균구하기(Course s[], int n, int* total, double* avg) {

    int i;

    *total = 0;
    *avg = 0;
    for (i = 0; i < n; i++) {
        *total += s[i].score;
    }
    *avg = (double)(*total) / n;//자동 형변환
    printf("총점과 평균을 계산했습니다!\n\n");

}

void swap(Course* a, Course* b) {

    Course temp;
    printf("원래거: %d %d", a->score, b->score);
    temp = *a;
    *a = *b;
    *b = temp;
    printf("바뀐거: %d %d", a->score, b->score);
}

void 성적표보기(Course s[], int n) {


    int i;

    printf("----------------------------------------------------------------------------\n");
    printf(" No.        과목명           담당교수        점수    학점  \n");
    printf("----------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%d", i + 1);
        printf("%20s  %20s        %3d    %3s \n", s[i].title, s[i].prof, s[i].score, s[i].grade);
    }
    printf("----------------------------------------------------------------------------\n");

}

void 정렬하기(Course s[], int n) {

    printf("정렬하기는 여러분이 만들어보세요 \n");
    int i, j, k;
    Course temp;
    char temp_char[100] = "";

    for (j = 0; j < n; j++) {
        for (i = 0; i < n - 1; i++) {
            if (s[i].score < s[i + 1].score)//그 다음게 더 크면 앞으로 간다.
            {
                //점수교환
                swap(&s[i], &s[i + 1]);
            }
        }

    }


}

int main() {

    //과목 최대개수는 10개
    //Course 과목정보[10] = { 0 };//malloc?

    //원래선언한거
    Course* 과목정보 = NULL;


    int i, 과목개수 = 0;
    int 총점 = 0;
    double 평균 = 0;
    int menu;
    char 화일이름[100] = "성적.txt";
    int flag = 0;

    //과목수 입력받기 -> 입력함수, 출력함수 작성하기
    while (1) {
        showMenu();
        printf("메뉴를 입력하세요 : ");
        scanf("%d", &menu);

        if (menu == 0) break;
        if (menu == 1) {
            // 성적읽기(화일이름, 과목정보, &과목개수);
            성적읽기_pointer(화일이름, &과목정보, &과목개수);
            flag = 1;
        }
        if (menu == 2) 학점구하기(과목정보, 과목개수);
        if (menu == 3) 총점_평균구하기(과목정보, 과목개수, &총점, &평균);
        if (menu == 4) 정렬하기(과목정보, 과목개수);

        if (menu == 5) 성적표보기(과목정보, 과목개수, 총점, 평균);

        printf("\n");
        printf("짱구가 수강한 과목수 : %d  총점 :%d  평균 :%.2lf \n", 과목개수, 총점, 평균);

    }

    printf("짱구의 성적표보기 시스템을 종료합니다.");

}