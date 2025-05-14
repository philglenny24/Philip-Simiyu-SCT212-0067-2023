#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverse_list (struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr!=NULL){
        struct ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void print_list(struct ListNode* head) {
    struct ListNode* temp=head;
    while(temp!=NULL) {
        printf("%d ->", temp->val);
        temp=temp->next;
    }
    printf("NULL\n");
}

struct ListNode* create_node(int val) {
    struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val=val;
    newNode->next=NULL;
    return newNode;
}
int main() {
    struct ListNode* head=create_node(1);
    head->next=create_node(2);
    head->next->next=create_node(3);
    head->next->next->next=create_node(4);

    printf("Original list:\n");
    print_list(head);

    head=reverse_list(head);

    printf("Reversed list:\n");
    print_list(head);

    return 0;
}
