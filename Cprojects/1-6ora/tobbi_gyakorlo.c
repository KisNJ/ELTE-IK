#include <stdio.h>
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int my_pow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
void print_pascal_triangle(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            long long num = factorial(i) / (factorial(j) * factorial(i - j));
            printf("%lld ", num);
        }
        printf("\n");
    }
}
int main() {
    int year;
    scanf("%d", &year);
    is_leap_year(year) ? printf("Szökőév!\n") : printf("Nem szökőév\n");
    printf("%lu\n", sizeof(short));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(long));
    printf("%lu\n", sizeof(unsigned long));
    printf("%lu\n", sizeof(long long));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));
    printf("%lu\n", sizeof(long double));

    unsigned int a = 0;
    unsigned int ui_max_val = my_pow(2, sizeof(a) * 8) - 1;
    printf("Unsigned int max: %u\n", ui_max_val);
    printf("Unsigned int max  val + 1: %u\n", ui_max_val + 1);

    printf("Pascal-háromszög\n");
    printf("n: ");
    int n;
    scanf("%d", &n);
    print_pascal_triangle(n);
    return 0;
}
