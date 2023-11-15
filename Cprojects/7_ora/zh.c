#include <stdio.h>

#define LIMIT 50000

int main()

{

    for (int i = 0; i < LIMIT; i++) {

        char c = getchar();
if (c == EOF) {
			break;
		}
        printf("%c", c);
    }

    return 0;
}
