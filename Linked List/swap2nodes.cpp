/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* head) 
{
    if(head->next==NULL)
        return head;
    
    ListNode *prev=NULL, *c=head, *n=head->next, *newHead;
    while(n!=NULL)
    {
        c->next=n->next;
        n->next=c;
        if(prev==NULL)
        {
            prev=c;
            newHead=n;
        }
        else
        {
            prev->next=n;
        }
        prev=c;
        if(c->next==NULL)
            break;
        else
        {
            c=c->next;
            n=c->next;
        }
    }
    return newHead;
}
