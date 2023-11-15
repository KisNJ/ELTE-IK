#include <stdbool.h>
#include <stdio.h>

#define ROWS 10
#define COLS 10
#define SHIP_KIND_COUNT 4

#define HORIZONTAL '-'
#define VERTICAL '|'

void init(int table[ROWS][COLS], int number_of_ships[SHIP_KIND_COUNT]);
bool submit(int table[ROWS][COLS], unsigned char x, int y, int length,
            char direction, int number_of_ship[SHIP_KIND_COUNT]);
void printTable(int table[ROWS][COLS]);
bool is_valid_placement(int table[ROWS][COLS], unsigned char base_x, int base_y,
                        int length, char direction);
bool is_valid_length(int number_of_ships[SHIP_KIND_COUNT], int length);
void place_on_board(int table[ROWS][COLS], unsigned char x, int y, int length,
                    char direction);

int main(int argc, char *argv[]) {
    int table[ROWS][COLS];
    // 1 2 1 1
    int number_of_ships[SHIP_KIND_COUNT];
    init(table, number_of_ships);
    printTable(table);
    submit(table, 'A', 2, 2, HORIZONTAL, number_of_ships);
    submit(table, 'A', 2, 2, HORIZONTAL, number_of_ships);
    submit(table, 'A', 3, 2, HORIZONTAL, number_of_ships);
    submit(table, 'C', 8, 3, '^', number_of_ships);
    submit(table, 'C', 8, 3, VERTICAL, number_of_ships);
    submit(table, 'J', 9, 3, VERTICAL, number_of_ships);
    printTable(table);

    return 0;
}

void init(int table[ROWS][COLS], int number_of_ships[SHIP_KIND_COUNT]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = 0;
        }
    }

    for (int i = 0; i < SHIP_KIND_COUNT; i++) {
        number_of_ships[i] = 0;
    }
}

void printTable(int table[ROWS][COLS]) {
    printf("   ");
    for (int i = 'A'; i <= 'J'; i++) {
        printf("%c ", i);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j == 0) {
                printf("%d", i + 1);
            }
            if (j + 1 == COLS)
                printf("%d\n", table[i][j]);
            else if (j == 0 && i + 1 > 9)
                printf(" %d ", table[i][j]);
            else if (j == 0)
                printf("  %d ", table[i][j]);
            else
                printf("%d ", table[i][j]);
        }
    }
}

bool submit(int table[ROWS][COLS], unsigned char x, int y, int length,
            char direction, int number_of_ships[SHIP_KIND_COUNT]) {
    // Check wheter direction is valid
    if (direction != HORIZONTAL && direction != VERTICAL) {
        printf("Helytelen irány!\n");
        return false;
    }

    if (!is_valid_length(number_of_ships, length)) {
        return false;
    }

    if (!is_valid_placement(table, x, y, length, direction)) {
        return false;
    }

    place_on_board(table, x, y, length, direction);
    number_of_ships[length - 2]++;
    return true;
}
bool is_valid_placement(int table[ROWS][COLS], unsigned char base_x, int base_y,
                        int length, char direction) {
    base_x -= 'A';
    base_y--;
    int x = base_x, y = base_y;
    for (int k = 0; k < length; k++) {
        if (x < 0 || x > 9 || y < 0 || y > 9) {
            printf("A hajó nem fér el a táblán!\n");
            return false;
        }
        for (int j = base_y - 1; j < base_y + 2; j++) {
            for (int i = base_x - 1; i < base_x + 2; i++) {
                if (i >= 0 && i < COLS && j >= 0 && j < ROWS &&
                    table[j][i] == 1) {
                    printf("Van szomszédos hajó!\n");
                    return false;
                }
            }
        }
        if (direction == HORIZONTAL) {
            x++;
        } else {
            y++;
        }
    }
    return true;
}

bool is_valid_length(int number_of_ships[SHIP_KIND_COUNT], int length) {
    int index = length - 2;
    if (index < 0 || index >= SHIP_KIND_COUNT) {
        printf("Helytelen méret!\n");
        return false;
    }

    if ((length == 3 && number_of_ships[index] == 2) ||
        (length != 3 && number_of_ships[index] == 1)) {
        printf("Már nem tehetsz le ilyen hosszúságű hajót\n");
        return false;
    }

    return true;
}
void place_on_board(int table[ROWS][COLS], unsigned char x, int y, int length,
                    char direction) {
    x -= 'A';
    y--;
    for (int i = 0; i < length; i++) {
        table[y][x] = 1;
        if (direction == HORIZONTAL) {
            x++;
        } else {
            y++;
        }
    }
}
