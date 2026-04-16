#include <stdio.h>
#include <stdlib.h>

// Tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Check if two trees are identical
int isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return 1;
    if (p == NULL || q == NULL) return 0;

    if (p->val != q->val) 
    return 0;

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

// Check subtree
int isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL) return 0;
    if (isSameTree(root, subRoot)) return 1;

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

int main() {
    // Root tree: [1,2,3,4,5]
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Subtree: [2,4,5]
    struct TreeNode* subRoot = newNode(2);
    subRoot->left = newNode(4);
    subRoot->right = newNode(5);

    if (isSubtree(root, subRoot)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}