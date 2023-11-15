#include <ctype.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// The program only works with maxium 26 x 26 grid (A-Z 0-25)
#define ROWS 10
#define COLS 10
#define MAX_VAL (10 * 10)

void drawTable(int table[ROWS][COLS], int shown_table[ROWS][COLS]);
void initTable(int table[ROWS][COLS], int n);
bool includes(int table[], int n, int val);
int bound(int min, int curr, int max);
void countNeighbourMines(int table[ROWS][COLS]);
void makeZerosVisible(int table[ROWS][COLS], int i, int j,
                      int shown_table[ROWS][COLS]);
bool resolveOnInput(int table[ROWS][COLS], char *input,
                    int shown_table[ROWS][COLS]);
bool onlyMinesRemain(int shown_table[ROWS][COLS], int number_of_mines);

// ===== SEARCH =====
int nextInRow(int table[ROWS][COLS], int i, int j);
int prevInRow(int table[ROWS][COLS], int i, int j);
int nextInCol(int table[ROWS][COLS], int i, int j);
int prevInCol(int table[ROWS][COLS], int i, int j);
int bRightDia(int table[ROWS][COLS], int i, int j);
int bLeftDia(int table[ROWS][COLS], int i, int j);
int tRightDia(int table[ROWS][COLS], int i, int j);
int tLeftDia(int table[ROWS][COLS], int i, int j);
// =====        =====

int searched_tiles[100] = {0};
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Provide the number of mines as the first parameter to the "
               "program!");
        return 1;
    }
    int number_of_mines = bound(3, atoi(argv[1]), 30);
    srand((unsigned)time(NULL));

    int table[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // 0 -> don't show the value
    // 1 -> show the value
    // 2 -> tile marked by flag, don't show the value
    // 3 -> exploded mine
    int shown_table[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    if (strcmp(argv[1], "load") == 0 && argc == 3) {
        char *name = argv[2];
        if (name == NULL) {
            puts("Couldn't open file.");
            return -1;
        }

        FILE *file = fopen(name, "rb");
        if (file == NULL) {
            puts("Couldn't open file.");
            return false;
        }
        for (int i = 0; i < ROWS; i++) {
            fread(table[i], sizeof(table[i][0]), COLS, file);
        }
        for (int i = 0; i < ROWS; i++) {
            fread(shown_table[i], sizeof(shown_table[i][0]), COLS, file);
        }
        fclose(file);
    } else {
        initTable(table, number_of_mines);
        countNeighbourMines(table);
    }

    char INPUT[255];
    bool lost = false;
    do {
        drawTable(table, shown_table);

        printf("Input: ");
        fgets(INPUT, 255, stdin);
        int new_line_loc = strcspn(INPUT, "\n");
        INPUT[new_line_loc] = '\0';
        lost = resolveOnInput(table, INPUT, shown_table);
        if (!lost && onlyMinesRemain(shown_table, number_of_mines))
            break;
    } while (!lost);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (shown_table[i][j] != 3)
                shown_table[i][j] = 1;
        }
    }
    drawTable(table, shown_table);
    if (lost)
        printf("\x1B[31mYou lost!\n");
    else
        printf("\x1B[32mYou win!\n");
    return 0;
}
bool onlyMinesRemain(int shown_table[ROWS][COLS], int number_of_mines) {
    int shown_count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (shown_table[i][j] == 1)
                shown_count++;
        }
    }
    return shown_count + number_of_mines == ROWS * COLS;
}
bool resolveOnInput(int table[ROWS][COLS], char *input,
                    int shown_table[ROWS][COLS]) {

    if (strncmp(input, "save", 4) == 0 && strchr(input, ' ') != NULL) {
        strtok(input, " ");
        char *name = strtok(NULL, " ");
        if (name == NULL) {
            return false;
        }
        FILE *file = fopen(name, "wb");
        if (file == NULL) {
            return false;
        }
        for (int i = 0; i < ROWS; i++) {
            fwrite(table[i], sizeof(table[i][0]), COLS, file);
        }
        for (int i = 0; i < ROWS; i++) {
            fwrite(shown_table[i], sizeof(shown_table[i][0]), COLS, file);
        }
        fclose(file);
        return false;
    }
    if (strncmp(input, "load", 4) == 0 && strchr(input, ' ') != NULL) {
        return false;
    }
    if (strlen(input) < 2) {
        return false;
    }
    // The input has three forms:  1. a4
    //                             2. [f|F]:a4 this means to put flag
    //                             3. [^f|F]:a4 remove flag at position

    char delim[] = ":";
    char input_copy[255];
    strncpy(input_copy, input, 255);

    char *first_part = strtok(input_copy, delim);
    char *last_part = strtok(NULL, delim);

    int column_index, row_index;

    // The 1st form
    if (last_part == NULL) {
        row_index = toupper(input[0]) - 'A';
        column_index = atoi(input + 1);
    }
    // 2nd and 3rd forms
    else {
        row_index = toupper(last_part[0]) - 'A';
        column_index = atoi(last_part + 1);
    }

    if (row_index >= ROWS || row_index < 0 || column_index >= COLS ||
        column_index < 0)
        return false;

    if (shown_table[row_index][column_index] == 1) {
        return false;
    }

    if (strlen(input) == 2) {

        shown_table[row_index][column_index] = 1;
        if (table[row_index][column_index] == -1) {
            shown_table[row_index][column_index] = 3;
            return true;
        }

        if (table[row_index][column_index] == 0) {
            printf("Row: %d Col: %d, val=%d\n", 0, 0, shown_table[0][0]);
            makeZerosVisible(table, row_index, column_index, shown_table);
        }
    }

    if (strlen(input) >= 3) {
        bool to_flag = toupper(input[0]) == 'F';
        shown_table[row_index][column_index] = to_flag ? 2 : 0;
        printf("Row: %d Col: %d, val=%d\n", row_index, column_index,
               shown_table[row_index][column_index]);
    }

    return false;
}

void makeZerosVisible(int table[ROWS][COLS], int i, int j,
                      int shown_table[ROWS][COLS]) {
    if (searched_tiles[i * 10 + j] == 1) {
        return;
    }

    if (nextInRow(table, i, j) >= 0 && shown_table[i][j + 1] != 2) {
        shown_table[i][j + 1] = 1;
    }
    if (prevInRow(table, i, j) >= 0 && shown_table[i][j - 1] != 2) {
        shown_table[i][j - 1] = 1;
    }
    if (nextInCol(table, i, j) >= 0 && shown_table[i + 1][j] != 2) {
        shown_table[i + 1][j] = 1;
    }
    if (prevInCol(table, i, j) >= 0 && shown_table[i - 1][j] != 2) {
        shown_table[i - 1][j] = 1;
    }
    if (bRightDia(table, i, j) >= 0 && shown_table[i + 1][j + 1] != 2) {
        shown_table[i + 1][j + 1] = 1;
    }
    if (bLeftDia(table, i, j) >= 0 && shown_table[i + 1][j - 1] != 2) {
        shown_table[i + 1][j - 1] = 1;
    }
    if (tRightDia(table, i, j) >= 0 && shown_table[i - 1][j + 1] != 2) {
        shown_table[i - 1][j + 1] = 1;
    }
    if (tLeftDia(table, i, j) >= 0 && shown_table[i - 1][j - 1] != 2) {
        shown_table[i - 1][j - 1] = 1;
    }

    searched_tiles[i * 10 + j] = 1;
    if (nextInRow(table, i, j) == 0 && searched_tiles[i * 10 + j + 1] == 0)
        makeZerosVisible(table, i, j + 1, shown_table);

    if (prevInRow(table, i, j) == 0 && searched_tiles[i * 10 + j - 1] == 0)
        makeZerosVisible(table, i, j - 1, shown_table);

    if (nextInCol(table, i, j) == 0 && searched_tiles[(i + 1) * 10 + j] == 0)
        makeZerosVisible(table, i + 1, j, shown_table);

    if (prevInCol(table, i, j) == 0 && searched_tiles[(i - 1) * 10 + j] == 0)
        makeZerosVisible(table, i - 1, j, shown_table);

    if (bRightDia(table, i, j) == 0 &&
        searched_tiles[(i + 1) * 10 + j + 1] == 0)
        makeZerosVisible(table, i + 1, j + 1, shown_table);

    if (bLeftDia(table, i, j) == 0 && searched_tiles[(i + 1) * 10 + j - 1] == 0)
        makeZerosVisible(table, i + 1, j - 1, shown_table);
    if (tRightDia(table, i, j) == 0 && searched_tiles[(i - 1) * 10 + j + 1])
        makeZerosVisible(table, i - 1, j + 1, shown_table);
    if (tLeftDia(table, i, j) == 0 && searched_tiles[(i - 1) * 10 + j - 1])
        makeZerosVisible(table, i - 1, j - 1, shown_table);
}
void drawTable(int table[ROWS][COLS], int shown_table[ROWS][COLS]) {
    // printf("\e[1;1H\e[2J");
    for (int i = 0; i < COLS; i++) {
        if (i == 0)
            printf("  ");
        printf("\x1B[35m%d  ", i);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j == 0)
                printf("\x1B[35m%c \x1B[37m", i + 'A');

            switch (shown_table[i][j]) {
            case 1:
                if (table[i][j] == -1)
                    printf("\x1B[35mb  \x1B[37m");
                else
                    printf("\e[0;32m%d  \x1B[37m", table[i][j]);
                break;
            case 2:
                printf("\x1B[34mP  \x1B[37m");
                break;
            case 3:
                printf("\x1B[31mb  \x1B[37m");
                break;
            default:
                printf("\x1B[33m*  \x1B[37m");
                break;
            }
        }
        printf("\n");
    }
}

void initTable(int table[ROWS][COLS], int n) {
    int mine_positions[n];
    memset(mine_positions, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        int random_val = rand() % (COLS * ROWS);

        while (includes(mine_positions, n, random_val)) {
            random_val = rand() % MAX_VAL;
        }
        mine_positions[i] = random_val;
    }

    for (int i = 0; i < n; i++) {
        const int current_val = mine_positions[i];

        int row_index = current_val / ROWS;
        int column_index = current_val % COLS;
        table[row_index][column_index] = -1;
    }
}

void countNeighbourMines(int table[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbour_mines = 0;
            if (table[i][j] == -1)
                continue;
            if (nextInRow(table, i, j) == -1)
                neighbour_mines++;

            if (prevInRow(table, i, j) == -1)
                neighbour_mines++;

            if (nextInCol(table, i, j) == -1)
                neighbour_mines++;

            if (prevInCol(table, i, j) == -1)
                neighbour_mines++;

            if (bRightDia(table, i, j) == -1)
                neighbour_mines++;

            if (bLeftDia(table, i, j) == -1)
                neighbour_mines++;

            if (tRightDia(table, i, j) == -1)
                neighbour_mines++;

            if (tLeftDia(table, i, j) == -1)
                neighbour_mines++;

            table[i][j] = neighbour_mines;
        }
    }
}
bool includes(int table[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (table[i] == val)
            return true;
    }
    return false;
}

int bound(int min, int curr, int max) {
    if (curr <= min)
        return min;
    if (curr >= max)
        return max;
    return curr;
}

// ===== SEARCH FUNCTIONS =====

// ROW
int nextInRow(int table[ROWS][COLS], int i, int j) {
    if (j + 1 < COLS)
        return table[i][j + 1];
    return -2;
}
int prevInRow(int table[ROWS][COLS], int i, int j) {
    if (j - 1 >= 0)
        return table[i][j - 1];
    return -2;
}

// COL
int nextInCol(int table[ROWS][COLS], int i, int j) {
    if (i + 1 < ROWS)
        return table[i + 1][j];
    return -2;
}
int prevInCol(int table[ROWS][COLS], int i, int j) {
    if (i - 1 >= 0)
        return table[i - 1][j];
    return -2;
}

// DIAGONAL
int bRightDia(int table[ROWS][COLS], int i, int j) {
    if (i + 1 < ROWS && j + 1 < COLS)
        return table[i + 1][j + 1];
    return -2;
}

int bLeftDia(int table[ROWS][COLS], int i, int j) {
    if (i + 1 < ROWS && j - 1 >= 0)
        return table[i + 1][j - 1];
    return -2;
}

int tRightDia(int table[ROWS][COLS], int i, int j) {
    if (i - 1 >= 0 && j + 1 < COLS)
        return table[i - 1][j + 1];
    return -2;
}

int tLeftDia(int table[ROWS][COLS], int i, int j) {
    if (i - 1 >= 0 && j - 1 >= 0)
        return table[i - 1][j - 1];
    return -2;
}
