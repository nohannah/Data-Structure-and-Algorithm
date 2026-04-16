#include <stdio.h>
#include <stdlib.h>

// Tree node definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build complete binary tree from array
struct TreeNode* buildTree(int arr[], int i, int n) {
    if (i >= n) return NULL;

    struct TreeNode* root = newNode(arr[i]);
    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);

    return root;
}

// Invert tree
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
    return NULL;

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Print level order (BFS)
void printLevelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* node = queue[front++];
        printf("%d ", node->val);

        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }

    printf("\n");
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;

    struct TreeNode* root = buildTree(arr, 0, n);

    printf("Original Tree: ");
    printLevelOrder(root);

    invertTree(root);

    printf("Inverted Tree: ");
    printLevelOrder(root);

    return 0;
}