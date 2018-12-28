#include <stdio.h>

void func1(int* pt){
    *pt = 5; // ポインタが指す先の変数の中身を5に
}

void func2(int** pt){
    **pt = 6; // ポインタが指す先のポインタが指す先の変数の中身を6に
}

int main(void){
    int a;
    func1(&a);
    printf("a=%d\n\n",a);
	
	int* b = &a;
	func2(&b);
	printf("a=%d\n", a);
	printf("*b=%d\n\n", *b);
	
	func1(b);
	printf("a=%d\n", a);
	printf("*b=%d\n\n", *b);
	
	return 0;
}