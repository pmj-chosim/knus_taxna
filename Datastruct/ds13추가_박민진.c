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
    else if (data == node->data) {
        printf("A %d : %d cannot be inserted\n",data, data);
        return node;
    }
    else {
        printf("%d cannot be inserted\n", data);
        return node;
    }
    return node;
}

int search(Node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void levelOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    levelOrder(node->left);
    levelOrder(node->right);
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
    char command;
    int data;
    printf("ÄÄÇ»ÅÍÇÐºÎ 2022117119 ¹Ú¹ÎÁø\n\n");
    FILE* inFile = fopen("in4.txt", "r");
    if (inFile == NULL) {
        printf("Cannot open in.txt\n");
        return 1;
    }

    while (fscanf(inFile, " %c%d", &command, &data) != EOF) {
        if (command == 'A') {
            root = insert(root, data, 1);
            printf("A %d: ", data);
            levelOrder(root);
            printf("\n");
        }
        else if (command == 'S') {
            int result = search(root, data);
            if (result) {
                printf("S %d: %d is in T\n", data, data);
            }
            else {
                printf("S %d: %d is not in T\n", data, data);
            }
        }
    }
    fclose(inFile);
    freeTree(root);
    return 0;
}
