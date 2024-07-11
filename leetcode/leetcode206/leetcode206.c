/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newHead = NULL;
    struct ListNode* temp = head;
    while(temp){//将当前的temp的next指向newHead
        struct ListNode* after = temp->next;
        temp->next = newHead;
        newHead = temp;
        temp = after;
    }
    return newHead;
}