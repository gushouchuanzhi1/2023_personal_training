/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dum = malloc(sizeof(struct ListNode));
    dum->next = head;dum->val = 0;
    int length = 0;
    struct ListNode* temp = head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    temp = dum;
    for(int i = 0; i < length - n; i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    struct ListNode* newHead = dum->next;  // 获取新的头节点
    free(dum);  // 释放虚拟头节点的内存
    return newHead;  // 返回新的头节点
}