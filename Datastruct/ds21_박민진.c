#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26

char inf[SIZE][SIZE];
char search[SIZE][SIZE];

char** resultString;
int* resultHash;

int parsetohash(char* s, int ds) {
	int sum = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		sum += (int)s[i];
	}
	return sum;
}

void printHashTable(int* resultHash, char** resultString, int ds) {
	printf("Hash table: \n");
	for (int i = 0; i < ds; i++) {
		printf("%d : ", i);
		if (resultString[i]) {
			printf("%s (%d)", resultString[i], resultHash[i]);
		}
		printf("\n");
	}
}

void division(int ds, int infnum) {
	resultString = (char**)malloc(sizeof(char*) * ds);
	resultHash = (int*)malloc(sizeof(int) * ds);

	for (int i = 0; i < ds; i++) {
		resultString[i] = NULL;
		resultHash[i] = -1;
	}

	for (int i = 0; i < infnum; i++) {
		int hashk = parsetohash(inf[i], ds);
		int hashkey = hashk % ds;
		if (resultString[hashkey] == NULL) {
			resultString[hashkey] = inf[i];
			resultHash[hashkey] = hashk;
		}
		else {
			int mege = hashkey;
			while (mege < ds && resultString[mege] != NULL) {
				mege++;
			}
			if (mege == ds) {
				mege = 0;
			}
			while (mege != hashkey && resultString[mege] != NULL) {
				mege++;
				if (mege == ds) {
					mege = 0;
				}
			}
			if (mege != hashkey) {
				resultString[mege] = inf[i];
				resultHash[mege] = hashk;
			}
			else {
				printf("Hash table is full.\n");
				break;
			}
		}
	}
	printHashTable(resultHash, resultString, ds);
}


void searchindata(int ds, int searchnum) {
	for (int i = 0; i < searchnum; i++) {
		int hashk = parsetohash(search[i], ds);
		int originalHashKey = hashk % ds;
		int hashkey = originalHashKey;
		while (hashkey < ds && resultString[hashkey] != NULL && strcmp(resultString[hashkey], search[i]) != 0) {
			hashkey++;
			if (hashkey == ds) {
				hashkey = 0; // 순환 검색을 위해 hashkey를 0으로 설정
			}
		}
		if ( resultString[hashkey] != NULL && strcmp(resultString[hashkey], search[i]) == 0) {
			printf("%s : %d\n", search[i], hashkey);
		}
		else {
			printf("%s : %d\n", search[i], -1);
		}
	}
}


int main() {
	FILE* fp;
	if ((fp = fopen("021_in_2.txt", "r")) == NULL) {
		printf("Cannot open file in.\n");
		return 1;
	}

	int num = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s", inf[num]);
		num++;
	}
	fclose(fp);

	int divisionstandard;
	scanf("%d", &divisionstandard);

	division(divisionstandard, num);

	if ((fp = fopen("021_search_2.txt", "r")) == NULL) {
		printf("Cannot open file search.\n");
		return 1;
	}

	int searchnum = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s", search[searchnum]);
		searchnum++;
	}
	fclose(fp);

	searchindata(divisionstandard, searchnum);

	free(resultString);
	free(resultHash);

	return 0;
}
