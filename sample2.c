#include <stdio.h>

void func1(char* pt){
    pt[0] = '1';
	pt[1] = '2';
	pt[2] = '3';
}

void func2(char** pt){
    **pt = '4';
	*(*pt + 1) = '5';
	*(*pt + 2) = '6';
}

void func3(char** pt){
    (*pt)[0] = '7';
	(*pt)[1] = '8';
	(*pt)[2] = '9';
}


int main(void){
    char a[4] = "000";
    func1(a);
    printf("a=%s\n\n",a);
	
	char* b = a;
	func2(&b);
	printf("a=%s\n", a);
	printf("b=%s\n\n", b);
	
	func1(b);
	printf("a=%s\n", a);
	printf("b=%s\n\n", b);
	
	func3(&b);
	printf("a=%s\n", a);
	printf("b=%s\n\n", b);

	return 0;
}