#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct {
    int weight;
    int vertex1;
    int vertex2;
} Edge;

void insertionSort(Edge edges[], int n) {
    int i, j;
    Edge key;

    for (i = 1; i < n; i++) {
        key = edges[i];
        j = i - 1;

        while (j >= 0 && edges[j].weight > key.weight) {
            edges[j + 1] = edges[j];
            j = j - 1;
        }
        edges[j + 1] = key;
    }
}

int main() {
    FILE* file = fopen("017_2.txt", "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    int n;
    fscanf_s(file, "%d", &n);

    int adjacencyMatrix[MAX_SIZE][MAX_SIZE] = { 0 };
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            fscanf_s(file, "%d", &adjacencyMatrix[i][j]);
        }
    }

    fclose(file);

    //입력 끝

    Edge edges[MAX_SIZE * MAX_SIZE];
    int numEdges = 0;

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                edges[numEdges].weight = adjacencyMatrix[i][j];
                edges[numEdges].vertex1 = i;
                edges[numEdges].vertex2 = j;
                numEdges++;
            }
        }
    }

    insertionSort(edges, numEdges);

    printf("컴퓨터학부 202211119 박민진\n");
    printf("문제 1\n");
    for (i = 0; i < numEdges; i++) {
        printf("%d (%d,%d)\n", edges[i].weight, edges[i].vertex1, edges[i].vertex2);
    }

    return 0;
}
