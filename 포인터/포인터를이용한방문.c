//#define ROW 3
//#define COLS 3
//#include <stdio.h>
//
////������ �迭���� �迭�� ������ �� �� ũ�⸦ ������ �� ����
//double get_row_average(int m[][COLS], int r) {//r: �ش� �� ��ȣ
//	int* p, * endp;
//	double sum = 0.0;
//
//	p = &m[r][0];//�����ּ�
//	endp = &m[r][COLS];//���ּ�+1
//
//	while (p < endp) {//���ּұ��� üũ(enpd: ���ּ�+1)
//		sum += *p++;//p�� �ְ�, p�ּ� �̵�
//	}
//	sum /= COLS;// �������� ������. 
//	return sum;
//}
//
//int main() {
//	int ar[ROW][COLS] = { {1,2,3},{10,20,30},{100,200,300} };
//	double result;
//
//	result = get_row_average(ar, 1);//1���� ����� ����
//	printf("%lf\n", result);
//
//	return 0;
//}