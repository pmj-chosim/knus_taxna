#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int visited[MAX_SIZE];
int** adjMatrix;

void dfs(int v, int n)
{
    visited[v] = 1;
    printf("%d ", v + 1);
    for (int w = 0; w < n; w++)
        if (adjMatrix[v][w] && !visited[w])
            dfs(w, n);
}

int main()
{
    printf("ÄÄÇ»ÅÍÇÐºÎ ¹Ú¹ÎÁø 2022117119\n\n");
    int n, i, j, input;
    FILE* file = fopen("in2-3.txt", "r"); //in-1.txt in2-3.txt
    fscanf(file, "%d", &n);

    adjMatrix = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        adjMatrix[i] = (int*)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(file, "%d", &adjMatrix[i][j]);
        }
    }
    fclose(file);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    while (1)
    {
        printf("scanf ÀÔ·Â: ");
        scanf("%d", &input);
        if (input == -1)
            break;

        for (i = 0; i < n; i++)
            visited[i] = 0;

        dfs(input - 1, n);
        printf("\n");
    }

   

    return 0;
}
