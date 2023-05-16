#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int level;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data, int level) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->level = level;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int data, int level) {
    if (node == NULL) {
        return newNode(data, level);
    }
    if (data < node->data) {
        node->left = insert(node->left, data, level + 1);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data, level + 1);
    }
    return node;
}

int search(Node* root, int data) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == data) {
        return root->level;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    Node* root = NULL;
    int data;
    FILE* inFile = fopen("in2.txt", "r");
    if (inFile == NULL) {
        printf("Cannot open in.txt\n");
        return 1;
    }

    while (fscanf(inFile, "%d", &data) != EOF) {
        root = insert(root, data, 1);
    }
    fclose(inFile);

    printf("학부: 컴퓨터학부 학번:2022117119 이름: 박민진\n");

    FILE* searchFile = fopen("search2.txt", "r");
    if (searchFile == NULL) {
        printf("Cannot open search.txt\n");
        freeTree(root);
        return 1;
    }

    while (fscanf(searchFile, "%d", &data) != EOF) {
        int level = search(root, data);
        if (level == -1) {
            printf("F ");
        }
        else {
            printf("%d ", level);
        }
    }
    fclose(searchFile);
    printf("\n");

    freeTree(root);
    return 0;
}
