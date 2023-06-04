#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b,temp)((temp = a),(a=b),(b=temp))

typedef struct element {
	int s;
	char c;
} element;

int listMergeS(element a[], int link[], int start1, int start2) {
	int last1, last2, lastResult = 0;
	for (last1 = start1, last2 = start2; last1 && last2;) {
		if (a[last1].s >= a[last2].s)
		{
			link[lastResult] = last1;
			lastResult = last1;
			last1 = link[last1];
		}
		else
		{
			link[lastResult] = last2;
			lastResult = last2;
			last2 = link[last2];
		}
	}
	if (last1 == 0)
	{
		link[lastResult] = last2;
	}
	else
	{
		link[lastResult] = last1;
	}
	return link[0];
}

int listMergeC(element a[], int link[], int start1, int start2) {
	int last1, last2, lastResult = 0;
	for (last1 = start1, last2 = start2; last1 && last2;) {
		if (a[last1].c >= a[last2].c)
		{
			link[lastResult] = last1;
			lastResult = last1;
			last1 = link[last1];
		}
		else
		{
			link[lastResult] = last2;
			lastResult = last2;
			last2 = link[last2];
		}
	}
	if (last1 == 0)
	{
		link[lastResult] = last2;
	}
	else
	{
		link[lastResult] = last1;
	}
	return link[0];
}


int rmergeSort(element a[], int link[], int left, int right, int n) {
	if (left >= right)
	{
		return left;
	}
	int mid = (left + right) / 2;
	if (n == 1) return listMergeS(a, link, rmergeSort(a, link, left, mid, n), rmergeSort(a, link, mid + 1, right, n));
	else listMergeC(a, link, rmergeSort(a, link, left, mid, n), rmergeSort(a, link, mid + 1, right, n));
}

void P1(element a[], int link[], int left, int right, int n) {
	if (n == 1)
	{
		rmergeSort(a, link, left, right, 1);
	}
	else
	{
		rmergeSort(a, link, left, right, 2);
	}
	for (int i = link[0]; i != 0; i = link[i])
	{
		printf("%d %c\n", a[i].s, a[i].c);
	}
}

void adjustS(element a[], int root, int n) {
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].s;
	child = 2 * root;
	while (child <= n)
	{
		if ((child < n) && (a[child].s >= a[child + 1].s)) child++;
		if (rootkey <= a[child].s) break;
		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void adjustC(element a[], int root, int n) {
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].c;
	child = 2 * root;
	while (child <= n)
	{
		if ((child < n) && (a[child].c >= a[child + 1].c)) child++;
		if (rootkey <= a[child].c) break;
		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void heapSort(element a[], int n, int mode) {
	int i, j;
	element temp;

	if (mode == 1)
	{
		for (i = n / 2; i > 0; i--)
		{
			adjustS(a, i, n);
		}
		printf("Min heap:\n");
		for (int i = 1; i <= n; i++)
		{
			printf("%d %c\n", a[i].s, a[i].c);
		}
		for (i = n - 1; i > 0; i--)
		{
			SWAP(a[1], a[i + 1], temp);
			adjustS(a, 1, i);
		}
	}
	else
	{
		for (i = n / 2; i > 0; i--)
		{
			adjustC(a, i, n);
		}
		printf("Min heap:\n");
		for (int i = 1; i <= n; i++)
		{
			printf("%d %c\n", a[i].s, a[i].c);
		}
		for (i = n - 1; i > 0; i--)
		{
			SWAP(a[1], a[i + 1], temp);
			adjustC(a, 1, i);
		}
	}
}

void P2(element a[], int n, int mode) {
	heapSort(a, n, mode);
	printf("Sorted list:\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d %c\n", a[i].s, a[i].c);
	}
}

int main() {
	printf("컴퓨더학부 2022117119 박민진\n");
	FILE* f;
	fopen_s(&f, "in2.txt", "r");
	element arr[20];
	int link[20] = { 0, };
	if (f == NULL)
	{
		return -1;
	}
	int i = 1;
	while (!feof(f))
	{
		fscanf_s(f, "%d %c ", &arr[i].s, &arr[i].c);
		i++;
	}
	int n;
	printf("문제 1 : \n");
	scanf_s("%d", &n);
	P1(arr, link, 1, i - 1, n);
	printf("문제 2 : \n");
	scanf_s("%d", &n);
	P2(arr, i - 1, n);
}