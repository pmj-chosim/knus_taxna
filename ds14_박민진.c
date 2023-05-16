#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void printGivenLevel(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    }
    else {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node* root) {
    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        printGivenLevel(root, i);
    }
    printf("\n");
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int isNodeExist(Node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    }
    else if (root->data > data) {
        return isNodeExist(root->left, data);
    }
    else {
        return isNodeExist(root->right, data);
    }
}

int main() {
    printf("컴퓨터학부 2022117119 박민진\n\n");
    FILE* in = fopen("014_in2.txt", "r");
    if (in == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Node* root = NULL;
    int value;
    while (fscanf(in, "%d", &value) != EOF) {
        root = insert(root, value);
    }
    fclose(in);

    while (root != NULL) {
        printLevelOrder(root);
        printf("Scanf: ");
        int k;
        scanf_s("%d", &k);

        if (k < 0) {
            break;
        }
        else {
            if (isNodeExist(root, k)) {
                root = deleteNode(root, k);
            }
            else {
                printf("Not exist\n");
            }
        }
    }
    return 0;
}
