#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Works only for part 1

void clean_line(char* line, size_t size) {
    memset(line, 0, size);
}

void skip_integer(char** line) {
    while (**line == ' ' || **line == '\t') {
        (*line)++;
    }
    while (isdigit(**line) || **line == '-') {
        (*line)++;
    }
    while (**line == ' ' || **line == '\t') {
        (*line)++;
    }
}


int is_safe(char* line) {
    char* ptr = line;
    int safe = 1;
    int increasing = 0;

    int n = 0;
    sscanf(ptr, "%d", &n);
    skip_integer(&ptr);

    int c_n;
    while (sscanf(ptr, "%d", &c_n) == 1) {
        if ((abs(c_n - n) == 0) || (abs(c_n - n) > 3)) {
            return 0;
        }
        if (((increasing > 0) && ((c_n - n) < 0)) || ((increasing < 0) && ((c_n - n) > 0))) {
            return 0;
        }
        increasing = c_n - n;
        n = c_n;
        skip_integer(&ptr);
    }
    return safe;
}

int main(int argc, char* argv[]) {
    FILE* stream = fopen("red-nosed_reports.txt", "r");

    int safe = 0;

    char line[100];
    while (fgets(line, sizeof(line), stream)) {
        safe += is_safe(line);
        clean_line(line, sizeof(line));
    }
    fclose(stream);
    printf("Safe count: %d\n", safe);

    return 0;
}
