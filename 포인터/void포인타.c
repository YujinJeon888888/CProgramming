//#include <stdio.h>
//int main(void) {
//	int a[] = { 10, 20, 30, 40, 50 };
//	char* str[] = { "abcd","efghhi!!!"};
//	void* vp;
//	//��¹��� �־� Ȯ���غ�����.
//	vp = (int*)a; // ����
//	vp = (int*)&a[2]; // ����
//	// *vp = 35; // ����
//	*(int*)vp = 35; // ����
//	// vp++; // ���ۿ���. +4 �� �ƴ� +1�� ����.
//	vp = (int*)a; //�����迭�� ����Ŵ
//
//	
//	//���1
//	//printf(" % d \n ", *(int*)(vp));
//	//printf(" % d \n ", *((int*)vp + 1));
//	//printf(" % d \n ", *((int*)vp + 2));
//	//printf(" % d \n ", *((int*)vp + 3));
//	
//	//����ȯ�Ͽ� ����ϴ� �Ϳ� ��������. vp++�� �ȵȴ�(void�ϱ�)
//	//���2
//	printf(" % d \n ", *((int*)vp)++);
//	printf(" % d \n ", *((int*)vp)++);
//	printf(" % d \n ", *((int*)vp)++);
//	printf(" % d \n ", *((int*)vp)++);
//	
//	//�ȵȴ�.
//	//printf(" % d \n ", *((int*)vp + sizeof(int)));
//	//printf(" % d \n ", *((int*)vp+(sizeof(int)*2)));
//	
//	vp = (char*)str[0]; //���ڿ��� ����Ŵ
//	printf("%s \n", (char*)(vp));
//	return 0;
//}
