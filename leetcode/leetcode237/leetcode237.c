/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* temp;
    temp = node;
    int value = temp->next->val;
    node->val = value;
    node->next=temp->next->next;
}