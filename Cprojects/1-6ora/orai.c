#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long factorial(unsigned int x);
int main(int argc, char **argv) {
	// what0.c
	// a fun függvényben az int *p csak egy másolat, a main függvényben lévő p nek ugyanaz marad az értéke
	
	// what1.c
	// *p++; p-t előbb elmozdítja aztán adja vissza az értéket
	// *++p; előbb eltolom utána dereferálom
	// --*p; előbb dereferálom utána csökkentem
	
	// what2.c
	// *&a  &*a , ugyanúgy a címét kapom meg
	
	// what3.c
	// csak sima int** pointer
	
	// what4.c
	// int a[][3] = {1,2,3,4,5,6};
	// int (*ptr)[3] = a; // ha a-t dereferálnám ami az első 3 elemű tömb címét tárolja, akkor egy három elemű tömböt kapok, ezért ez a type, azaz "a" egy három elemű tömbre pointer, általánosan a tömb nevű változó az első elem címe (arra mutató pointer)
	// 2 3 \\ 5 6
	
	// what5.c
	// gh\0, p+=4 => ez eltolja p-t ij-re, aztán [-1] vissza meg eggyel és dereferál
	

	// ======== FILE ============
	FILE *fp;

	// módok
	printf("A parancssori argumentumok száma: %d\n",argc);
	for(int i=0; i < argc; i++) {
		printf("Az %d. argumentum: %s\n",i,argv[i]);
	}

	printf("\n\n2. feladat\n\n");
	char BUF[255];
	char BUF_2[255];

	fgets(BUF, 255, stdin);
	strcpy(BUF_2,BUF);
	printf("A beolvasott szavak: %s", BUF);
	
	char delim[] = " ";
	char *token = strtok(BUF, delim);

	//puts("Az 5-nél hosszabb szavak:");
	while(token != NULL) {
		char *current_word = token;

		if (strlen(current_word) > 5) {
			puts("5-nél hosszabb szó: ");
			printf("%s\n", current_word);
			}

		if (strchr(current_word,'x') != NULL) {
			puts("x-et tartalmazó szó: ");
			printf("%s\n", current_word);
		}

		if (strstr(current_word, "alma")) {
			puts("Az alma szót tartalmazó szó: ");
			printf("%s\n", current_word);
		}

		if (strcmp(current_word, "cica") == 0)
			printf("Ez a szó a cica\n");
		else
			printf("Ez a szó nem a cica\n");

		token = strtok(NULL, delim);
	}

	puts("Az eredeti szó:");
	printf("%s\n", BUF_2);


	printf("\n3. feladat\n");
	if (argc == 3) {
		printf("A szorzat: %d\n",atoi(argv[1]) * atoi(argv[2]));
	}

	printf("\n4. feladat\n");
	printf("%lld\n", factorial(3));
	printf("%llu\n", factorial((unsigned int)50));

	printf("\n5. feladat\n");
	fp = fopen("player.txt", "w");
	fprintf(fp, "knjasd\n");

	fp = fopen("even_numbers.txt","a");

	int ints[6] = {12,34,56,77,21,876};
	for(int i = 0; i < 6 ; i++ ) {
		if (ints[i] % 2 == 0) {}
			//fprintf(fp, "%d, ",ints[i]);
	}
	//fprintf(fp, "\n");

	char LINE[256];
	FILE *pfp = fopen(argv[3], "r");
	char delim2[] = ", ";
	char *token2;
	while(fgets(LINE, 256,pfp) != NULL) {
		//printf("%s", LINE);
		token2 = strtok(LINE, delim2);
		int sum = 0;
		while (token2 != NULL) {
			printf("%s\n",token2);
			sum += atoi(token2);
			token2 = strtok(NULL, delim2);
		}
		printf("%d\n", sum);
		
	}

	printf("\n6. feladat\n");
	fclose(fp);
	fclose(pfp);
	return 0;
}

unsigned long long factorial(unsigned int x) {
	if (x == 0) {
		return  1;
	}
	return x * factorial(x-1);
}

void logger (int id, char msg[]){

	char output[256];
	switch (id) {
		case 0:
			strcpy(output,"INFO");
			break;
		case 1:
			strcpy(output,"WARNING");
			break;
		case 2:
			strcpy(output,"ERROR");
			break;
		default:
			strcpy(output, "LOG");
			break;
	}
	strcpy(output, " - ");
}
