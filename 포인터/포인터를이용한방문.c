//#define ROW 3
//#define COLS 3
//#include <stdio.h>
//
////다차원 배열에서 배열을 전달할 때 열 크기를 생략할 수 없음
//double get_row_average(int m[][COLS], int r) {//r: 해당 행 번호
//	int* p, * endp;
//	double sum = 0.0;
//
//	p = &m[r][0];//시작주소
//	endp = &m[r][COLS];//끝주소+1
//
//	while (p < endp) {//끝주소까지 체크(enpd: 끝주소+1)
//		sum += *p++;//p값 넣고, p주소 이동
//	}
//	sum /= COLS;// 열갯수로 나눈다. 
//	return sum;
//}
//
//int main() {
//	int ar[ROW][COLS] = { {1,2,3},{10,20,30},{100,200,300} };
//	double result;
//
//	result = get_row_average(ar, 1);//1행의 평균을 구함
//	printf("%lf\n", result);
//
//	return 0;
//}