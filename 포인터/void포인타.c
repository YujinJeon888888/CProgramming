//#include <stdio.h>
//int main(void) {
//	int a[] = { 10, 20, 30, 40, 50 };
//	char* str[] = { "abcd","efghhi!!!"};
//	void* vp;
//	//출력문을 넣어 확인해보세요.
//	vp = (int*)a; // 가능
//	vp = (int*)&a[2]; // 가능
//	// *vp = 35; // 오류
//	*(int*)vp = 35; // 가능
//	// vp++; // 동작오류. +4 가 아닌 +1로 연산.
//	vp = (int*)a; //정수배열을 가리킴
//
//	
//	//방법1
//	//printf(" % d \n ", *(int*)(vp));
//	//printf(" % d \n ", *((int*)vp + 1));
//	//printf(" % d \n ", *((int*)vp + 2));
//	//printf(" % d \n ", *((int*)vp + 3));
//	
//	//형변환하여 사용하는 것에 주의하자. vp++은 안된다(void니까)
//	//방법2
//	printf(" % d \n ", *((int*)vp)++);
//	printf(" % d \n ", *((int*)vp)++);
//	printf(" % d \n ", *((int*)vp)++);
//	printf(" % d \n ", *((int*)vp)++);
//	
//	//안된다.
//	//printf(" % d \n ", *((int*)vp + sizeof(int)));
//	//printf(" % d \n ", *((int*)vp+(sizeof(int)*2)));
//	
//	vp = (char*)str[0]; //문자열을 가리킴
//	printf("%s \n", (char*)(vp));
//	return 0;
//}
