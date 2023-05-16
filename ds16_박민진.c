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

void printAdjacencyList(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d:", i + 1);
        for (nodePointer w = graph[i]; w; w = w->link)
            printf(" %d", w->vertex + 1);
        printf("\n");
    }
}

void bfs(int v)
{
    nodePointer w;
    nodePointer front = NULL;
    nodePointer rear = NULL;

    printf("%d ", v + 1);
    visited[v] = 1;
    nodePointer newNode = (nodePointer)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->link = NULL;
    front = newNode;
    rear = newNode;

    while (front != NULL) {
        nodePointer current = front;
        front = front->link;

        for (w = graph[current->vertex]; w; w = w->link) {
            if (!visited[w->vertex]) {
                printf("%d ", w->vertex + 1);

                //addq
                newNode = (nodePointer)malloc(sizeof(node));
                newNode->vertex = w->vertex;
                newNode->link = NULL;
                if (front == NULL)
                    front = rear = newNode;
                else {
                    rear->link = newNode;
                    rear = newNode;
                }

                visited[w->vertex] = 1;
            }
        }
    }

    printf("\n");
}




int main()
{
    printf("학부: 컴퓨터학부 학번: 2022117119 이름: 박민진\n");
    int n, i, j, input;
    FILE* file = fopen("in2.txt", "r");
    fscanf(file, "%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            fscanf(file, "%d", &input);
            if (input == 1)
            {
                addEdge(i, j);
                addEdge(j, i);
            }
        }
    }
    fclose(file);

    printAdjacencyList(n);

    while (1)
    {
        printf("scanf 입력: ");
        scanf("%d", &input);
        if (input == -1)
            break;

        for (i = 0; i < n; i++)
            visited[i] = 0;

        bfs(input - 1);
    }

    return 0;

}