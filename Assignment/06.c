#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Define node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Reverse linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Create new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Print linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create list: 0 -> 1 -> 2 -> 3
    struct ListNode* head = newNode(0);
    head->next = newNode(1);
    head->next->next = newNode(2);
    head->next->next->next = newNode(3);

    printf("Original list: ");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}