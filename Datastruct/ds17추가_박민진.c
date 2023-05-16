#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int visited[MAX_SIZE];
int graph[MAX_SIZE][MAX_SIZE];

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int InCycle(int v, int parent, int target) {
    visited[v] = 1;

    for (int i = 1; i <= MAX_SIZE; i++) {
        //dfs
        if (graph[v][i] == 1) {
            if (visited[i] == 0) {
                if (InCycle(i, v, target) == 1) {
                    return 1;
                }
            }
            else if (i != parent && i == target) {
                return 1;
            }
        }
    }

    return 0;
}




int main() {
    FILE* file = fopen("017_2.txt", "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    int n;
    fscanf_s(file, "%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int weight;
            fscanf_s(file, "%d", &weight);
            if (weight != 0) {
                addEdge(i, j);
            }
        }
    }fclose(file);
    //weight 저장 완


    

    printf("컴퓨터학부 2022117119 박민진\n");

    int target;
    while (1) {
        printf("scanf: ");
        scanf_s("%d", &target);
        if (target == -1) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
        }

        if (InCycle(target, -1, target) == 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}
