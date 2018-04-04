/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //This is a partially correct solution 
 //memory constarint is not satisfied

ListNode* mergeTwoLists(ListNode* A, ListNode* B) 
{
    ListNode *dummy=new ListNode(0);
    ListNode *current=dummy;
    
    while(A!=NULL&&B!=NULL)
    {
        if(A->val<B->val)
        {
            current->next=A;
            current=A;
            A=A->next;
        }
        else
        {
            current->next=B;
            current=B;
            B=B->next;
        }
    }
    if(A)
        current->next=A;
    else 
        current->next=B;
        
    return dummy->next;
}

ListNode* Solution::sortList(ListNode* A) 
{
    if(A==NULL||A->next==NULL)
        return A;
        
    ListNode *slow=A;
    ListNode *fast=A->next->next;
    
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    ListNode *r=sortList(slow->next);
    slow->next=NULL;
    ListNode *l=sortList(A);
    
    return mergeTwoLists(l,r);
}