/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* temp = dummyHead;
    while (temp->next != NULL) {
        if (temp->next->val == val) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    return dummyHead->next;
}