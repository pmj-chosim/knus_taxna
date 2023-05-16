#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int weight;
    int vertex1;
    int vertex2;
} Edge;

int parent[MAX_SIZE];
int rank[MAX_SIZE];

int Find(int i) {
    if (i != parent[i])
        parent[i] = Find(parent[i]);
    return parent[i];
}

void Union(int i, int j) {
    int ri = Find(i);
    int rj = Find(j);
    if (ri != rj) {
        if (rank[ri] > rank[rj])
            parent[rj] = ri;
        else if (rank[ri] < rank[rj])
            parent[ri] = rj;
        else {
            parent[ri] = rj;
            rank[rj]++;
        }
    }
}

void MakeSet(int i) {
    parent[i] = i;
    rank[i] = 0;
}

void quickSort(Edge arr[], int L, int R) {
    int left = L;
    int right = R;
    int pivot = arr[(L + R) / 2].weight;
    Edge temp;

    do {
        while (arr[left].weight < pivot)
            left++;
        while (arr[right].weight > pivot)
            right--;
        if (left <= right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);

    if (L < right)
        quickSort(arr, L, right);
    if (left < R)
        quickSort(arr, left, R);
}

void kruskal(Edge edges[], int numEdges, int numVertices) {
    for (int i = 0; i < numVertices; i++)
        MakeSet(i);

    quickSort(edges, 0, numEdges - 1);

    for (int i = 0; i < numEdges; i++) {
        int v1 = edges[i].vertex1;
        int v2 = edges[i].vertex2;

        if (Find(v1 - 1) != Find(v2 - 1)) {
            printf("%d (%d,%d)\n", edges[i].weight, v1, v2);
            Union(v1 - 1, v2 - 1);
        }
    }
}

int main() {
    FILE* file = fopen("in4.txt", "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    int adjacencyMatrix[MAX_SIZE][MAX_SIZE] = { 0 };
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            fscanf(file, "%d", &adjacencyMatrix[i][j]);
        }
    }

    fclose(file);

    Edge edges[MAX_SIZE * MAX_SIZE];
    int numEdges = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                edges[numEdges].weight = adjacencyMatrix[i][j];
                edges[numEdges].vertex1 = i + 1;
                edges[numEdges].vertex2 = j + 1;
                numEdges++;
            }
        }
    }

    printf("컴퓨터학부 202217119 박민진\n");
    kruskal(edges, numEdges, n);

    return 0;
}

