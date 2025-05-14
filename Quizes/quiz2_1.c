#include <stdio.h>
#include <stdbool.h>

struct ListNode{
    int val;
    struct ListNode *next;
};
bool has_cycle(struct ListNode *head){
    struct ListNode *slow=head;
    struct ListNode *fast=head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
int main(){
    struct ListNode node1 = {1,NULL};
    struct ListNode node2 = {2,NULL};
    struct ListNode node3 = {3,NULL};
    struct ListNode node4 = {4,NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;

    if(has_cycle(&node1)){
        printf("Cycle detected!\n");
    } else {
    printf("No cycle detected.\n");
    }
    return 0;
}
