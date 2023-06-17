#pragma once
#include "배틀함수.h"
#include "파일함수.h"

void 점수파일열기 (Player *p , char ID[]) {//플레이어의 점수랑, 입력한 아이디 필요하다.
	FILE* 읽기용 = NULL;
	FILE* 쓰기용 = NULL;
	int num=0;
	char str[100] = "";
	읽기용 = fopen("역대기록.txt", "r"); //실제 해당경로에 파일이 존재해야 함.
	if (읽기용 == NULL) { //성공하면 실제 파일의 위치가 저장되지만 실패시는 NULL.
		printf("파일이 없습니다. 파일 열기 실패\n");
		exit(1);
	}
	printf("\nUSER: %s %d\n\n", ID, (*p).score);//파일의 내용이 없을 때까지, 한 줄 씩 읽어 파일의 끝에 도달할 때까지
	while (1) {
		if (feof(읽기용) != 0) break;//끝나면 0이아닌 값 리턴

		//fscanf(fp1, "%d %s", &num, str);//띄어쓰기 전 문자열까지 읽고 다음에 숫자가 나와야 하는데 안 나와서 무한루프
		//내가 읽으려는 파일의 형식에 맞게 해야한다.
		fscanf(읽기용, "%s", str);
		fscanf(읽기용, "%d", &num);
	
		//fgets(str, 100, 읽기용);//fgets는 \n를 넣어준다.
		//질문: 마지막 게 두 번 찍힌다.
		if(str[0]!='\0')//처음 읽을 때 빈 거 읽히는 거 제외
			printf("%s %d\n", str, num);
	}
	//fp2 에 이어서 쓴다. 입력된 아이디와 점수를
	//읽기쓰기 분리: 꼭 읽기와 쓰기를 분리해야만 한다(안전성)
	//(읽기 기능 오픈하고 나서 닫고)
	fclose(읽기용); //파일 닫기
	//쓰기기능 오픈하고 나서 쓴다.
	쓰기용 = fopen("역대기록.txt", "a"); //실제 해당경로에 파일이 만들어 짐
	fprintf(쓰기용, "\n%s %d", ID, (*p).score);
	fclose(쓰기용); //파일 닫기(꼭 닫아준다)
} 
