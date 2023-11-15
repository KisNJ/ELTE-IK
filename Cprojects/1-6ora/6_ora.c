#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    // char c = getchar();
    char d;
    // while ((d = getchar()) != EOF) {
    //     printf("%c", d);
    // }
    while ( scanf("%c",&d)) {
        printf("%c", d);
    }
    scanf("%c", &d);
    return EXIT_SUCCESS;
}
