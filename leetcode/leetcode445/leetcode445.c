/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head){
    struct ListNode* newHead = NULL;
    while(head){
        struct ListNode* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    l1 = reverse(l1);
    l2 = reverse(l2);
    int sum=0;
    int i=0;
    struct ListNode*cur1=l1;
    struct ListNode*cur2=l2;
    struct ListNode*a=(struct ListNode*)malloc(sizeof(struct ListNode));
    a->next=NULL;
    a->val=-1;
    struct ListNode*b=a;
    while(cur1||cur2)
    {
        struct ListNode*c=(struct ListNode*)malloc(sizeof(struct ListNode));
        c->val=-1;
        c->next=NULL;
        b->next=c;
        b=b->next;
        if(cur1==NULL)
        {
            sum=0;
            sum=sum+cur2->val+i;
            cur2=cur2->next;
        }
        else if(cur2==NULL)
        {
            sum=0;
            sum=sum+cur1->val+i;
            cur1=cur1->next;
        }
        else
        {
            sum=0;
            sum=cur1->val+cur2->val+i;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        if(sum>=10)
        {
            b->val=sum%10;
            i=1;
        }
        else
        {
            b->val=sum;
            i=0;
        }
    }
    if(i==1)
    {
        struct ListNode*newl=(struct ListNode*)malloc(sizeof(struct ListNode));
        newl->val=1;
        newl->next=NULL;
        b->next=newl;
    }
    a->next=reverse(a->next);
    return a->next;
}