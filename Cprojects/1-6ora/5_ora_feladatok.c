#include <stdio.h>
#include <string.h>

void swap (int *a, int *b);
int sum (int *arr, int length);
int sum_by_first_last(int *first, int *last);
double avg_by_first_last(int *first, int *last);
int* local_s_ptr();
int smaller_index (int *f, int *l);
int my_strlen(char *p);
int my_strcmp(char *p1, char *p2);
int *max_by_pointer(int *arr, int length);

int main() {
	printf("\n1. feladat\n");
	int a = 15;
	int *b = &a;
	(*b)++;
	printf("%d\n",a);

	printf("\n2. feladat\n");
	int x = 35, y = 41;
	printf("x=%d, y=%d\n",x,y);
	swap(&x,&y);
	printf("x=%d, y=%d\n",x,y);

	int arr1[] = {1,2};
	int arr2[] = {3,4};
	printf("arr1[0] = %d, arr2[1] = %d\n", arr1[0], arr2[1]);
	swap(arr1, arr2 + 1); // &arr2[1] is jó lenne, arr1 alpból az első elem memória címét tárolja
	printf("arr1[0] = %d, arr2[1] = %d\n", arr1[0], arr2[1]);

	printf("\n3. feladat\n");
	int ertek = 123;
	int *mutato = &ertek;
	int **mutatora_mutato = &mutato;
	printf("%d és %d\n", *mutato, **mutatora_mutato);

	int ertek2 = 12;
	*mutatora_mutato = &ertek2;
	printf("%d és %d\n", *mutato, **mutatora_mutato);

	printf("\n4. feladat\n");
	printf("sizeof char* %lu\n", sizeof(char*));
	printf("sizeof int* %lu\n", sizeof(int*));
	printf("sizeof float* %lu\n", sizeof(float*));
	printf("sizeof char* %lu\n", sizeof(char*));
	printf("sizeof unsigned int* %lu\n", sizeof(unsigned int*));
	printf("sizeof double* %lu\n", sizeof(double*));

	//Nem lehet önmagára mutató pointer mert +1 * kell a bal oldalon
	
	printf("\n5. feladat\n");
	int arr[] = {10,11,5};
	printf("Az összeg: %d\n",sum(arr, 3));

	printf("\n6. feladat\n");
	//ha a hossznál többel indexelünk túl akkor szemét adat adódik hozzá az összeghez vagy segfault lesz
	printf("Az összeg utolso pointerrel: %d\n",sum_by_first_last(arr,arr + 3));
	//printf("Az összeg utolso pointerrel: %d\n",sum_by_index(arr,arr + 24)); ---garbage data

	printf("\n7. feladat\n");
	printf("Az átlag: %lf\n",avg_by_first_last(arr, arr + 3));

	printf("\n8. feladat\n");
	//Segmentation fault
	//printf("Deref functions local pointer %d", *local_s_ptr());

	printf("\n9. feladat\n");
	int *pt = NULL;
	// Segmentation fault
	//printf("Deref null PTR: %d\n", *pt);
	
	printf("\n10. feladat\n");
	// Szükséges mert a függvényből pointert nem térhet vissza, a mi általunk deklarárlt változó így módusolhat

	printf("\n11. feladat\n");
	printf("Kisebb indexű: %d\n", smaller_index(arr, arr+1));

	printf("\n12. feladat\n");
	printf("my_strlen(%s) == %d, strlen(%s) == %lu\n", "aa", my_strlen("aa"), "aa", strlen("aa"));
	printf("my_strlen(%s) == %d, strlen(%s) == %lu\n", "sdasdsfaa", my_strlen("sdasdsfaa"), "sdasdsfaa", strlen("sdasdsfaa"));
	printf("%lu\n",sizeof(int));
	printf("%lu\n",sizeof(long int));
	printf("%lu\n",sizeof(long long ));
	printf("my_strcmp(%s) == %d, strcmp(%s) == %d\n", "s és s", my_strcmp("s", "s"), "s és s", strcmp("s", "s"));
	printf("my_strcmp(%s) == %d, strcmp(%s) == %d\n", "aa és bb", my_strcmp("aa", "bb"),"aa és bb" , strcmp("aa","bb"));
	printf("my_strcmp(%s) == %d, strcmp(%s) == %d\n", "zf és bb", my_strcmp("zf", "bb"),"zf és bb" , strcmp("zf","bb"));

	printf("\n13. feladat\n");
	printf("Max value: %d\n", *max_by_pointer(arr, 3));
	// Tömb felére alkalmazható, ha length / 2 -ig megyek
	// Lehet 1 elemre alkalmazni ha length-nek 1-et adok meg
	// Ha függvényben deklarálunk változót amire pointert adunk vissza az nem lesz jó, mert a deklarálkt váltózó lekerül a  stackről
	
	
	printf("\n14. feladat\n");
	int array[] = {1, 23, 32, 21};
	int (*arr_ptr)[4] = &array;

	printf("\n15. feladat\n");
	int (*f_ptr) (int*, int) = &sum;
	int arr_2d[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
	};
	printf("%d\n", **arr_2d);

	return 0;
}
void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int sum (int *arr, int length) {
	//nem lehet a tömb méretét kitalálni
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += *(arr + i); // vagy arr[i]
	}
	return sum;
}

int sum_by_first_last(int *first, int *last) {
	int sum = 0;
	while (first < last) {
		sum += *first;
		first++;
	}
	return sum;
}

double avg_by_first_last(int *first, int *last) {
	// a hossz csak sima kivonás
	int length = last - first;
	int sum = sum_by_first_last(first,last);
	return (double)sum/length;
}

int* local_s_ptr(){
	int a = 15;
	return &a;
}

int smaller_index (int *f, int *l) {
	if (f < l)
		return 0;
	return 1;
}

int my_strlen(char *p) {
	int len = 0;
	while (*p != '\0') {
		len++;
		p++;
	}
	return len;
}

int my_strcmp(char *p1, char *p2) {
	unsigned long l1 = strlen(p1);
	unsigned long l2 = strlen(p2);

	for (unsigned long i = 0; i < l1 && i < l2; i++) {
		if (p1[i] < p2[i]) {
			return -1;
		}

		if (p1[i] > p2[i]) {
			return 1;
		}
	}
	return 0;
}

int *max_by_pointer(int arr[], int length) {
	int *max_ptr = arr;
	for (int i = 1; i < length; i++) {
		if (arr[i] > *max_ptr) {
			max_ptr = arr + i;
		}
	}
	return max_ptr;
}

int(*arr_ptr())[]{
	static int arr[] ={1,2,3};
	int (*arr_ptr)[] = &arr;
	return &arr;
}

int fn (int a ){
	return 5;
}
int  (*return_function()) (int) {
	return &fn;
}
