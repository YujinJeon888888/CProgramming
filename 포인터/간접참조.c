//#include <stdio.h>
//int main(void)
//{
//	int burger_kor[3] = { 3000, 2000, 4000 }; //예) 치즈, 햄에그, 더블샌드위치
//	int burger_usa[3] = { 3500, 2600, 5000 };
//	int burger_jap[3] = { 3200, 2700, 4500 };
//	int country;
//	int* p_burger = NULL;
//	printf("지역을 입력하시요:");
//	scanf("%d", &country);
//	if (country == 0) p_burger = burger_kor;
//	else if (country == 1) p_burger = burger_usa;
//	else p_burger = burger_jap;
//	printf("현지역에서의 햄버거 가격:");
//	printf("%d %d %d\n", p_burger[0], p_burger[1], p_burger[2]);
//	return 0;
//}