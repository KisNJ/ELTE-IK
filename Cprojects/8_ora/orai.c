#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str);
char *reverse_dynamic(char *str);
int *parity_sort(int *arr, size_t length);
void print_sort_nums_in(char *line);
int sort_longs(const void *a, const void *b);

int main(int argc, char **argv) {
    // 1. feladat
    {
        char str[21];
        fgets(str, 21, stdin);

        char *copy = malloc(strlen(str) + 1);
        for (size_t i = 0; i <= strlen(str); i++) {
            copy[i] = str[i];
        }
        printf("Original: %s\n", str);
        printf("Copy: %s\n", copy);
        free(copy);
    }

    // 2. feladat
    {
        char apple[50] = "almas";
        printf("%s\n", apple);
        reverse(apple);
        printf("%s\n", apple);
    }

    // 3. feladat
    {
        char apple[50] = "almas";
        printf("%s\n", apple);
        char *reversed = reverse_dynamic(apple);
        printf("%s\n", reversed);

        free(reversed);
    }

    // 4. feladat
    {
        char *words[5];
        for (int i = 0; i < 5; i++) {
            words[i] = malloc(64);
            if (words[i] == NULL) {
                return 1;
            }
        }

        for (int i = 0; i < 5; i++) {
            printf("%dth word: ", i + 1);
            fgets(words[i], 64, stdin);
            words[i][strcspn(words[i], "\n")] = '\0';
        }

        for (int i = 4; i >= 0; i--) {
            printf("%s\n", words[i]);
            free(words[i]);
        }
    }

    // 5-6. feladat
    {
        if (argc == 2) {
            int number = atoi(argv[1]);
            size_t read_in = 0;

            char **arr = malloc(sizeof(char *) * number);
            if (arr == NULL) {
                return 1;
            }
            for (int i = 0; i < number; i++) {
                arr[i] = malloc(64);
                printf("Reading in: ");
                fgets(arr[i], 64, stdin);

                arr[i][strcspn(arr[i], "\n")] = '\0';
                if (strcmp(arr[i], "END") == 0) {
                    break;
                }
                read_in++;
            }

            for (int i = read_in - 1; i >= 0; i--) {
                printf("%s\n", arr[i]);
                free(arr[i]);
            }
            free(arr);
        }
    }

    // 7. feladat
    {
        size_t length = 4;
        char **arr = malloc(sizeof(char *) * length);
        for (size_t i = 0; i < length; i++) {
            arr[i] = malloc(16);
        }
        size_t number_of_lines = 0;
        while (!feof(stdin)) {
            fgets(arr[number_of_lines], 16, stdin);
            arr[number_of_lines][strcspn(arr[number_of_lines], "\n")] = '\0';

            number_of_lines++;
            if (number_of_lines == length) {
                length *= 2;
                arr = realloc(arr, sizeof(char *) * length);
                for (size_t i = number_of_lines; i < length; i++) {
                    arr[i] = malloc(16);
                }
            }
        }

        puts("");
        for (size_t i = 0; i < number_of_lines; i++) {
            printf("%s\n", arr[i]);
        }
        for (size_t i = 0; i < length; i++) {
            free(arr[i]);
        }
        free(arr);
    }

    // 8. feladat
    {
#define LENGTH 7
        int arr[LENGTH] = {34, 512, 11, 17, 18, 19, 231};
        int *sorted = parity_sort(arr, LENGTH);
        for (size_t i = 0; i < LENGTH; i++) {
            // printf("%d\n",sorted[i]);
        }

        free(sorted);
    }

    // 9. feladat
    size_t length = 8;
    FILE *fp = fopen("numbers.txt", "r");

    char *line = malloc(sizeof(char) * length);
    char *current_position = line;

    while (1) {
        fgets(current_position, length - (current_position - line), fp);
        if (feof(fp)) {
            break;
        }
        if (line[strlen(line) - 1] == '\n') {
            print_sort_nums_in(line);
            current_position = line;
        } else {
            length *= 2;
            line = realloc(line, length);
            current_position = line + length / 2 - 1;
        }
    }

    free(line);
    fclose(fp);
    return 0;
}

void print_sort_nums_in(char *line) {
    char *initial = line;
    size_t length = 8;
    size_t i = 0;
    long *nums = malloc(sizeof(long) * length);
    char *end;
    for (;; i++) {
        if (i == length) {
            length *= 2;
            nums = realloc(nums, sizeof(long) * length);
        }
        errno = 0;
        const long num = strtol(line, &end, 10);

        if (end == line) {
            break;
        }

        const bool range_error = errno == ERANGE;
        if (range_error)
            printf("Number %.*s, to big %ld is stored\n", (int)(end - line),
                   line, num);
        nums[i] = num;
        line = end;
    }

    line = initial;
    qsort(nums, i, sizeof(long), sort_longs);
    for (size_t j = 0; j < i; j++) {
        printf("%ld ", nums[j]);
    }
    putchar('\n');
    free(nums);
}
int sort_longs(const void *a, const void *b) {
    long x = *(const long *)a;
    long y = *(const long *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}
void reverse(char *str) {
    size_t length = strlen(str);
    for (size_t i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

char *reverse_dynamic(char *str) {
    size_t length = strlen(str);
    char *reversed = malloc(length + 1);
    reversed[length] = '\0';

    for (size_t i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }

    return reversed;
}

int *parity_sort(int *arr, size_t length) {
    int *sorted = malloc(sizeof(int) * length);
    if (sorted == NULL) {
        return NULL;
    }
    int put_in = 0;
    for (size_t i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            sorted[put_in] = arr[i];
            put_in++;
        }
    }

    for (size_t i = 0; i < length; i++) {
        if (arr[i] % 2 == 1) {
            sorted[put_in] = arr[i];
            put_in++;
        }
    }
    return sorted;
}
