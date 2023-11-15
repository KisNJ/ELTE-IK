#include <stdio.h>

int fn (int a, int b);
unsigned long factorial (int n);
int *add(int x, int y);
int main() {
//	for (int i = 8; i < 50; i++) {
//		for (i = 0 ; i < 36; i += 10 ) {
//			printf("%d\n", i);
//		}
//	}
printf("%d\n",fn(3,4));
printf("%ld\n",factorial(33));
printf("%lu\n",factorial(33));

int *val = add(7, 4);
printf("Val of pointer return: %d", *val);
}

int fn (int x, int y) {
	return x + y;
}

unsigned long factorial (int n) {
	static int counter = 0;
	if ( n < 1 ) {
		counter++;
	}

	if (n <= 1) {
		return 1;
	}

	unsigned long value = 1;
	for (int i = 1; i <= n ; i++) {
		value *= i;
	}

	return value;
}

int *add(int x, int y) {
	// static változó lokálisan tárolja az értéket, megmarad a program futása során
	static int a;
	a = x + y;
	return &a;
}
