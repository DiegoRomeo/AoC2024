#include "stdio.h"
#include <stdlib.h>

int a[1000];
int b[1000];
int c[1000];

int n = sizeof(a) / sizeof(a[0]);

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) {
    FILE *stream = fopen("historian_hysteria.txt", "r");
    for (int i = 0; i < 1000; i++) {
        fscanf(stream, "%d%d", &a[i], &b[i]);
    }

    qsort(a, n, sizeof(int), comp);
    qsort(b, n, sizeof(int), comp);

    for (int i = 0; i < 1000; i++) {
        c[i] = abs(a[i] - b[i]);
    }

    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += c[i];
    }

    int similarity = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (a[i] == b[j]) {
                similarity += a[i];
            }
        }
    }

    printf("Sum: %d\n", sum);
    printf("Similarity: %d", similarity);
}