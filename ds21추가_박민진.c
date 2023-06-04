#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Result {
	char* s;
	int hash;
	struct Result* next;
} Result;

Result** result;

char inf[26][26];
char search[26][26];

int parsetohash(char* s, int ds) {
	int sum = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		sum += (int)s[i];
	}
	return sum;
}

void printHashTable(int ds) {
	printf("Hash table: \n");
	for (int i = 0; i < ds; i++) {
		printf("%d : ", i);
		Result* mege = result[i];
		while (mege != NULL) {
			printf("%s (%d)  ", mege->s, mege->hash);
			mege = mege->next;
		}
		printf("\n");
	}
}

void division(int ds, int infnum) {
	result = (Result**)malloc(sizeof(Result*) * ds);
	for (int i = 0; i < ds; i++) {
		result[i] = NULL;
	}

	for (int i = 0; i < infnum; i++) {
		int hashk = parsetohash(inf[i], ds);
		int hashkey = hashk % ds;

		Result* newNode = (Result*)malloc(sizeof(Result));
		newNode->s = inf[i];
		newNode->hash = hashk;
		newNode->next = NULL;

		if (result[hashkey] == NULL) {
			result[hashkey] = newNode;
		}
		else {
			Result* mege = result[hashkey];
			while (mege->next) {
				mege = mege->next;
			}
			mege->next = newNode;
		}
	}
	printHashTable(ds);
}

void searchindata(int ds, int searchnum) {
	for (int i = 0; i < searchnum; i++) {
		int hashk = parsetohash(search[i], ds);
		int hashkey = hashk % ds;
		Result* mege = result[hashkey];
		int found = 0;

		while (mege) {
			if (!strcmp(mege->s, search[i])) {
				printf("%s : %d\n", search[i], hashkey);
				found = 1;
				break;
			}
			mege = mege->next;
		}

		if (!found) {
			printf("%s : -1\n", search[i]);
		}
	}
}

int main() {
	printf("¹Ú¹ÎÁø 2022117119\n");
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
	scanf_s("%d", &divisionstandard);

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

	return 0;
}
