#include <stdio.h>
#define MAX_LENGTH 5

int hex_to_int(char hex_str[]);
int my_pow(int base, int exponent);
int good_input(char c) {
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'));
}
int main() {
    printf("okok asd s ");
    char input[MAX_LENGTH];
    int i = 0;
    do {
        char temp;
        scanf("%c", &temp);
        if (good_input(temp)) {
            input[i] = temp;
            i++;
        }
    } while (i < MAX_LENGTH - 1);
    i++;
    input[i] = '\0';
    printf("%d", hex_to_int(input));
    return 0;
}

int hex_to_int(char hex_str[]) {
    int length = MAX_LENGTH - 1;
    int decimal_value = 0;
    for (int i = 0; i < length; i++) {
        if (hex_str[i] >= 'a' && hex_str[i] <= 'f') {
            decimal_value += my_pow(16, length - i - 1) * (hex_str[i] - 87);
        } else {
            decimal_value += my_pow(16, length - i - 1) * (hex_str[i] - 48);
        }
    }
    return decimal_value;
}

int my_pow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
