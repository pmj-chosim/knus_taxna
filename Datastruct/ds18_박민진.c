#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct {
    int weight;
    int vertex1;
    int vertex2;
} Edge;



void quickSort(Edge arr[], int L, int R) {
    int left = L, right = R;
    int pivot = arr[(L + R) / 2].weight;    // pivot 설정 (가운데) 
    Edge temp;
    do
    {
        while (arr[left].weight < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        while (arr[right].weight > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
            left++;
            right--;
        }
    } while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 

  /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 

    if (left < R)
        quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}

void merge(Edge initList[], Edge mergedList[], int i, int m, int n)
{ /* the sorted lists initList[i:m] and initList[m+l:n] are merged to obtain
the sorted list mergedList[i:n] */
    int j, k, t;
    j = m + 1; /* index for the second sublist */
    k = i; /* index for the merged list */
    while (i <= m && j <= n) {
        if (initList[i].weight <= initList[j].weight)
            mergedList[k++] = initList[i++];
        else
            mergedList[k++] = initList[j++];
    }
    if (i > m) /* mergedList[k:n] = initList[j:n] */
        for (t = j; t <= n; t++)
            mergedList[t] = initList[t];
    else /* mergedList[k:n] = initList[i:m] */
        for (t = i; t <= m; t++)
            mergedList[k + t - i] = initList[t];
}
void mergePass(Edge initLIst[],Edge mergedList[], int n, int s)
{
    int i, j;
    for (i = 0; i <= n - 2 * s + 1; i += 2 * s)
        merge(initLIst, mergedList, i, i + s - 1, i + 2 * s - 1);
    if (i + s - 1 < n)
        merge(initLIst, mergedList, i, i + s - 1, n);
    else
        for (j = i; j <= n; j++)
            mergedList[j] = initLIst[j];
}

void mergeSort(Edge a[], int n) {
    int s = 1;
    Edge extra[MAX_SIZE];

    while (s < n) {
        mergePass(a, extra, n, s);
        s *= 2;
        mergePass(extra, a, n, s);
        s *= 2;
    }
}

void p1(Edge edges[],int numEdges ) {
    quickSort(edges,0, numEdges-1);
    printf("문제 1\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%d (%d,%d)\n", edges[i].weight, edges[i].vertex1, edges[i].vertex2);
    }
}

void p2(Edge edges[], int numEdges) {
    mergeSort(edges,numEdges - 1);
    printf("문제 2\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%d (%d,%d)\n", edges[i].weight, edges[i].vertex1, edges[i].vertex2);
    }
}


int main() {
    FILE* file = fopen("in2.txt", "r");
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
        for (j = i ; j <= n; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                edges[numEdges].weight = adjacencyMatrix[i][j];
                edges[numEdges].vertex1 = i;
                edges[numEdges].vertex2 = j;
                numEdges++;
            }
        }
    }
  
   

    printf("컴퓨터학부 202217119 박민진\n");
     p1(edges, numEdges);
     printf("\n\n");
     p2(edges, numEdges);
    return 0;
}
