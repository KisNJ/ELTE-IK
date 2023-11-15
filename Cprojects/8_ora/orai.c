#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str);
char *reverse_dynamic(char *str);
int *parity_sort(int *arr, size_t length);

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
#ifdef RUN_4
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

#endif /* ifdef RUN_4 */
    }

    // 5-6. feladat
    {
#ifdef RUN_5_6

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
#endif /* ifdef RUN_5_6 */
    }

    // 7. feladat
    {
        // size_t length = 4;
        // char **arr = malloc(sizeof(char *) * length);
        // for (size_t i = 0; i < length; i++) {
        //     arr[i] = malloc(16);
        // }
        // size_t number_of_lines = 0;
        // while (!feof(stdin)) {
        //     fgets(arr[number_of_lines], 16, stdin);
        //     arr[number_of_lines][strcspn(arr[number_of_lines], "\n")] = '\0';
        //
        //     number_of_lines++;
        //     if (number_of_lines == length) {
        //         length *= 2;
        //         arr = realloc(arr, sizeof(char *) * length);
        //         for (size_t i = number_of_lines; i < length; i++) {
        //             arr[i] = malloc(16);
        //         }
        //     }
        // }
        //
        // puts("");
        // for (size_t i = 0; i < number_of_lines; i++) {
        //     printf("%s\n", arr[i]);
        // }
        // for (size_t i = 0; i < length; i++) {
        //     free(arr[i]);
        // }
        // free(arr);
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
    FILE *fp = fopen("num.txt", "r");
    FILE *foutput = fopen("output.txt", "w");

    char *line = malloc(sizeof(char) * length);
    char *current_position = line;

    size_t full_line_length = 0;
    while (1) {
        fgets(current_position, length - (current_position - line), fp);
        if (feof(fp)) {
            break;
        }
        size_t current_part_length = strlen(current_position);
        full_line_length += current_part_length + 1;
        if (current_position[current_part_length - 1] == '\n') {
            for (size_t i = 0; i < full_line_length; i++) {
                printf("%c", line[i]);
            }
            full_line_length = 0;
            current_position = line;
        } else {
            length *= 2;
            line = realloc(line, length);
            current_position = line + length / 2;
        }
    }

    free(line);
    fclose(fp);
    fclose(foutput);
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
