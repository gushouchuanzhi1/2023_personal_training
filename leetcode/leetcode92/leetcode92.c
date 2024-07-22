/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Reverse the linked list starting from 'head' and return the new head
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* newHead = NULL;
    while (head) {
        struct ListNode* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) return head;

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* before = dummy;
    for (int i = 1; i < left; i++) {
        before = before->next;
    }
    struct ListNode* subHead = before->next;
    struct ListNode* subTail = subHead;
    for (int i = left; i < right; i++) {
        subTail = subTail->next;
    }
    struct ListNode* after = subTail->next;
    subTail->next = NULL;
    struct ListNode* newSubHead = reverse(subHead);
    before->next = newSubHead;
    subHead->next = after;
    head = dummy->next;
    free(dummy);
    return head;
}