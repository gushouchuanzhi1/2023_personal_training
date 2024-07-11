/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    struct ListNode* dum = malloc(sizeof(struct ListNode));
    dum->val = 0; dum->next = head;
    struct ListNode* temp = dum;
    while(temp->next != NULL && temp->next->next !=NULL){
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dum->next;

}