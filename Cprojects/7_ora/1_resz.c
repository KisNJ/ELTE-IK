#include <stdio.h>
#include "utils.h"

//void fn(int u, int u);
void static_test();

int outer = 8;
int main(){

	printf("%d\n", outer);
	outer++;
	outer++;
	outer++;
	printf("%d\n", outer);

	if (outer > 10){
		int c = 10;
	}
	//printf("%d\n", c); hiba
	{
		int a = 10;
		{
			printf("%d\n", a);
			int b = 2;

			{
				printf("%d\n", b);
				int c = 89;
			}

		}

	}

	static_test();
	static_test();
	static_test();
	static_test();

	int a = 5, b = 9;
	printf("a: %d, b: %d\n", a, b);
	swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);

	int *max = bigger(&a, &b);
	printf("bigger: %d\n", *max);


}

//void fn(int u, int u) { hiba redefinition of u
//	return;
//}

void static_test(){
	static int h = 1;
	h++;
	printf("Static h: %d\n",h);
}


