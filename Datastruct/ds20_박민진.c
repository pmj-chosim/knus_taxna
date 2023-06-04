#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define d 4
#define r 16

int* rear;
int* front;

typedef struct{
    char input[d + 1];
}element;

element a[100];

int digit(element num, int i) {
    if (num.input[i] >= '0' && num.input[i] <= '9') return num.input[i] - '0';
    else if (num.input[i] >= 'a' && num.input[i] <= 'f') return num.input[i] - 'a' + 10;
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
    fopen_s(&fp, "in2.txt", "r");
    int count = 0;
    char mege[5];
    while (fscanf_s(fp, "%4s", mege, sizeof(mege)) != EOF) {
        count++;
    }
    fclose(fp);
    //char** a = (char**)malloc(sizeof(char*) * (count + 2));
    //for (int i = 0; i <= count + 1; i++)
    //    a[i] = (char*)malloc(sizeof(char) * 5);
    int* link = (int*)malloc(sizeof(int) * (count + 1));


    fopen_s(&fp, "in2.txt", "r");
    for (int i = 1; i <= count; i++) {
        fscanf_s(fp, "%s", mege, sizeof(mege));
        strcpy_s(a[i].input, d + 1, mege);
    }
    fclose(fp);

    int first = radixSort(link, count);

    printf("2022117119 ¹Ú¹ÎÁø\n\n");

    for (int i = first; i <= count; i = link[i]) {
        printf("%s\n", a[i].input);
    }
    return 0;
}