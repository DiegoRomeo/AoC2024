#include "stdio.h"
#include "ctype.h"
#include <math.h>
#include <stdlib.h>


#define MAX_TEXT_LENGTH 100000
#define MAX_INT 10000


int parse_int(char* text, int i) {
    char intero[MAX_INT];
    int j = 0;
    if (!isdigit(text[i])) {
        return 0;
    }
    while (isdigit(text[i + j])) {
        intero[j] = text[i + j];
        j++;
    }
    if (j > 3) {
        return 0;
    }
    intero[j] = '\0';
    int n = atoi(intero);

    return n;
}

int main(int arc, char* argv[]) {
    char text[MAX_TEXT_LENGTH];
    FILE *file = fopen("day3.txt", "r");
    size_t text_length = fread(text, sizeof(char), MAX_TEXT_LENGTH, file);
    text[text_length++] = '\0';
    fclose(file);

    int sum = 0;
    int a, b = 0;
    int enabled = 1;
    int part2 = 1;  // Set to 0 if part 1 else 1
    for (int i = 0; i < text_length-4; i++) {
        a = 0;
        b = 0;

        if (text[i] == 'd' && text[i+1] == 'o' && text[i+2] == '(' && text[i+3] == ')' && part2) {
            enabled = 1;
            continue;
        }

        if (text[i] == 'd' && text[i+1] == 'o' && text[i+2] == 'n' && text[i+3] == '\'' && text[i+4] == 't' && text[i+5] == '(' && text[i+6] == ')' && part2) {
            enabled = 0;
            continue;
        }

        if (text[i] == 'm' && text[i+1] == 'u' && text[i+2] == 'l' && text[i+3] == '(' && enabled) {
            int j  = 4;
            a = parse_int(text, i+j);
            while (isdigit(text[i+j])) {
                j++;
            }
            if (text[i+j++] != ',') {
                continue;
            }
            b = parse_int(text, i+j);
            while (isdigit(text[i+j])) {
                j++;
            }
            if (text[i+j] == ')') {
                sum += a*b;
            }
        }
    }

    printf("Sum: %d", sum);
}