/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k == 0 || head == NULL || head->next == NULL) return head;
    int length = 1;
    struct ListNode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        length++;
    }
    k = k % length;
    if(k == 0) return head;
    temp->next = head;//成环
    //右移k个，等于从head结点（包括）数到第k+1个结点这个地方，k+1结点的next指向null
    temp = head;//重新赋值
    for (int i = 0; i < length - k - 1; i++) {
        temp = temp->next;
    }
    struct ListNode* ret = temp->next;
    temp->next = NULL;
    return ret;
}