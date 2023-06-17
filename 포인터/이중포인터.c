//#include <stdio.h>
//void set_proverb(char** q); //char *의 주소를 전달받으므로 ** 이다.
//int main(void)
//{
//	char* s = NULL;
//	set_proverb(&s); // s의 주소가 전달된다.
//	printf("selected proverb = %s\n", s);
//	return 0;
//}
//void set_proverb(char** q)//s주소를 받았다.q변수 안에는 s의 주소가 들어있음
//{
//	//static 으로 선언하여 프로그램이 실행되는 동안 공간을 유지한다. 
//	static char* str1 = "A friend in need is a friend indeed"; 
//	static char* str2 = "A little knowledge is a dangerous thing";
//	*q = str1;//q가 받은 것: s자체의 주소. s변수 안에 str1주소를 넣는다. 
//}