#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sum_of_div_not_self(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0)
            sum += i;
    }
    return sum;
}

double median(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if (length % 2 == 0) {
        return ((double)(arr[length / 2] + arr[length / 2 - 1])) / 2;
    }
    return arr[length / 2];
}

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int l, int r) {
    int i;
    if (l == r)
        printf("");
        //printf("%s\n", a);
    else {
        for (i = l; i <= r; i++) {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i));
        }
    }
}
bool possible_triangle(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a)
        return true;
    return false;
}
double area_from_3_sides(int a, int b, int c) {
    double s = (double)(a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
void max_area(int *arr, int length) {
    double max_area = 0;
    int a, b, c;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            for (int k = j + 1; k < length; k++) {
                if (possible_triangle(arr[i], arr[j], arr[k]) && max_area < area_from_3_sides(arr[i],arr[j],arr[k])) {
                    max_area = area_from_3_sides(arr[i], arr[j], arr[k]);
                    a = arr[i];
                    b = arr[j];
                    c = arr[k];
                }
            }
        }
    }

    printf("A legnagyobb terület: %lf, (%d, %d, %d) oldalakkal", max_area, a, b, c);
}
int main() {
    char arviz[] = "árvíztűrőtükörfúrógép";
    printf("%lu\n", sizeof(arviz));
    printf("%lu\n", strlen(arviz));

    int tomb[3] = {220, 130, 284};
    bool van_e = false;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (sum_of_div_not_self(tomb[i]) == tomb[j] &&
                tomb[i] == sum_of_div_not_self(tomb[j]))
                van_e = true;
        }
    }
    if (van_e)
        printf("Vannak barátságos számok!\n");
    else
        printf("Nincsenek barátságos számok!\n");

    char column[] = "Z";
    int val_of_chars = 0;
    for (size_t i = 0; i < strlen(column); i++) {
        val_of_chars += column[i] - 64;
    }
    int col_number = (strlen(column) - 1) * 25 + (val_of_chars);
    printf("%d\n", col_number);

    time_t t;
    srand((unsigned)time(&t));
    int arr100[100];
    for (int i = 0; i < 100; i++) {
        arr100[i] = rand() % 999;
    }
    printf("%lf\n", median(arr100, 100));

    int arr101[101];
    for (int i = 0; i < 101; i++) {
        arr101[i] = rand() % 999;
    }
    printf("%lf\n", median(arr101, 101));

    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n - 1);

    int sides[] = {1, 2, 2, 300, 20};
    max_area(sides, 5);

    printf("\nEgy mondatot!: ");
    char input[50];
    scanf("%49[^\n]s", input);
    int count = 0;
    char delim[] = " ";
    char *token = strtok(input, delim);
    while (token != NULL) {
        count++;
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }
    printf("A szavak száma %d\n", count);

    return 0;
}
