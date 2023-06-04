#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define d 10
#define r 27

int* rear;
int* front;

typedef struct {
    char input[d + 1];
}element;

element a[100];

int digit(element num, int i) {
    if (num.input[i] >= 'a' && num.input[i] <= 'z') return num.input[i] - 'a' + 1;
    else if (num.input[i] == ' ') return 0;
    return -1;
}

int radixSort(int link[], int n) {
    front = (int*)malloc(sizeof(int) * r);
    rear = (int*)malloc(sizeof(int) * r);
    int bin, current, first, last;
    first = 1;
    for (int i = 1; i < n; i++)
        link[i] = i + 1;
    link[n] = 0;
    for (int i = d - 1; i >= 0; i--) {
        for (bin = 0; bin < r; bin++)
            front[bin] = 0;
        for (current = first; current; current = link[current]) {
            bin = digit(a[current], i);
            if (front[bin] == 0)
                front[bin] = current;
            else
                link[rear[bin]] = current;
            rear[bin] = current;
        }
        for (bin = 0; bin < r && !front[bin]; bin++);
        first = front[bin]; last = rear[bin];

        for (bin++; bin < r; bin++) {
            if (front[bin]) {
                link[last] = front[bin]; last = rear[bin];
            }
        }
        link[last] = 0;
    }
    return first;
}

int main() {
    FILE* fp;
    fp = fopen("in4.txt", "r");
    int count = 0;
    char mege[11];
    while (fgets(mege, sizeof(mege), fp) != NULL) {
        count++;
    }
    fclose(fp);

    int* link = (int*)malloc(sizeof(int) * (count + 1));

    fp = fopen("in4.txt", "r");
    for (int i = 1; i <= count; i++) {
        fgets(mege, sizeof(mege), fp);
        mege[strcspn(mege, "\n")] = 0; 
        for (int j = strlen(mege); j < d; j++)
            mege[j] = ' '; 
        mege[d] = '\0'; // 
        strcpy(a[i].input, mege);
    }
    fclose(fp);

    int first = radixSort(link, count);

    printf("2022117119 ¹Ú¹ÎÁø\n\n");

    for (int i = first; i <= count; i = link[i]) {
        for (int j = 0; j < d && a[i].input[j] != ' '; j++)
            printf("%c", a[i].input[j]);
        printf("\n");
    }
    return 0;
}
