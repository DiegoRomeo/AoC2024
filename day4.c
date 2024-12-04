#include "stdio.h"

#define MAX_LINES 140
#define MAX_LINE_LENGTH 1000

void read_input(char* file_name, char arr[MAX_LINES][MAX_LINE_LENGTH]) {
    FILE* fp = fopen(file_name, "r");
    int i = 0;
    while(fgets(arr[i], MAX_LINE_LENGTH, fp) != NULL) {
        i++;
    } 
}

int solve_part1(char text[MAX_LINES][MAX_LINE_LENGTH]) {
    int count = 0;

    // Horizontal
    for (int i = 0; i < MAX_LINES; i++) {
        for (int j = 0; j < MAX_LINE_LENGTH - 3; j++) {
            if (text[i][j] == 'X' && text[i][j+1] == 'M' && text[i][j+2] == 'A' && text[i][j+3] == 'S') {
                count++;
            }
            if (text[i][j+3] == 'X' && text[i][j+2] == 'M' && text[i][j+1] == 'A' && text[i][j] == 'S') {
                count++;
            }
        }
    }

    // Diagonal (left to right)
    for (int i = 0; i < MAX_LINES-3; i++) {
        for (int j = 0; j < MAX_LINE_LENGTH - 3; j++) {
            if (text[i][j] == 'X' && text[i+1][j+1] == 'M' && text[i+2][j+2] == 'A' && text[i+3][j+3] == 'S') {
                count++;
            }
            if (text[i+3][j+3] == 'X' && text[i+2][j+2] == 'M' && text[i+1][j+1] == 'A' && text[i][j] == 'S') {
                count++;
            }
        }
    }

    // Vertical
    for (int i = 0; i < MAX_LINES; i++) {
        for (int j = 0; j < MAX_LINE_LENGTH; j++) {
            if (text[i][j] == 'X' && text[i+1][j] == 'M' && text[i+2][j] == 'A' && text[i+3][j] == 'S') {
                count++;
            }
            if (text[i+3][j] == 'X' && text[i+2][j] == 'M' && text[i+1][j] == 'A' && text[i][j] == 'S') {
                count++;
            }
        }
    }

    // Diagonal (right to left)
    for (int i = 0; i < MAX_LINES-3; i++) {
        for (int j = 3; j < MAX_LINE_LENGTH; j++) {
            if (text[i][j] == 'X' && text[i+1][j-1] == 'M' && text[i+2][j-2] == 'A' && text[i+3][j-3] == 'S') {
                count++;
            }
            if (text[i+3][j-3] == 'X' && text[i+2][j-2] == 'M' && text[i+1][j-1] == 'A' && text[i][j] == 'S') {
                count++;
            }
        }
    }

    return count;
}


int solve_part2(char text[MAX_LINES][MAX_LINE_LENGTH]) {
    int count = 0;

    for (int i = 0; i < MAX_LINES - 2; i++) {
        for (int j = 0; j < MAX_LINE_LENGTH - 2; j++) {
            if (text[i][j] == 'M' && text[i+1][j+1] == 'A' && text[i+2][j+2] == 'S') {
                if (text[i][j+2] == 'M' && text[i+2][j] == 'S') {
                    count++;
                }
                if (text[i][j+2] == 'S' && text[i+2][j] == 'M') {
                    count++;
                }
            }

            if (text[i][j] == 'S' && text[i+1][j+1] == 'A' && text[i+2][j+2] == 'M') {
                if (text[i][j+2] == 'M' && text[i+2][j] == 'S') {
                    count++;
                }
                if (text[i][j+2] == 'S' && text[i+2][j] == 'M') {
                    count++;
                }
            }
        }
    }

    return count;
}


int main() {
    char text[MAX_LINES][MAX_LINE_LENGTH];
    read_input("day4.txt", text);

    int part1 = solve_part1(text);
    int part2 = solve_part2(text);

    printf("Part 1: %d\n", part1);
    printf("Part 2: %d", part2);
}