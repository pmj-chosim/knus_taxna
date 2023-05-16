#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct node
{
    int vertex;
    struct node* link;
} node;

typedef node* nodePointer;

int visited[MAX_SIZE];
nodePointer graph[MAX_SIZE];

void dfs(int v)
{
    nodePointer w;
    visited[v] = 1;
    printf("%d ", v + 1);
    for (w = graph[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}

void addEdge(int u, int v)
{
    nodePointer newNode = (nodePointer)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->link = NULL;

    if (graph[u] == NULL || graph[u]->vertex > v)
    {
        newNode->link = graph[u];
        graph[u] = newNode;
    }
    else
    {
        nodePointer cur = graph[u];
        while (cur->link != NULL && cur->link->vertex < v)
            cur = cur->link;

        newNode->link = cur->link;
        cur->link = newNode;
    }
}

int main()
{
    printf("ÄÄÇ»ÅÍÇÐºÎ ¹Ú¹ÎÁø 2022117119\n");
    int n, i, j, input;
    FILE* file = fopen("in2-3.txt", "r"); //in2-3.txt
    fscanf(file, "%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(file, "%d", &input);
            if (input == 1)
                addEdge(i, j);
        }
    }
    fclose(file);

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d:", i + 1);
        for (nodePointer w = graph[i]; w; w = w->link)
            printf(" %d", w->vertex + 1);
        printf("\n");
    }

    while (1)
    {
        printf("scanf ÀÔ·Â: ");
        scanf("%d", &input);
        if (input == -1)
            break;

        for (i = 0; i < n; i++)
            visited[i] = 0;

        dfs(input - 1);
        printf("\n");
    }

    return 0;
}
