/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head)
{
    if(head==NULL||head->next==NULL)
        return head;
    ListNode* secondHead=head->next;
    head->next=NULL;
    ListNode* reversez=reverse(secondHead);
    secondHead->next=head;
    return reversez;
}
int Solution::lPalin(ListNode* head) 
{
    int count=0;
    ListNode* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    ListNode *mid=head;
    int m=(count/2);
    
    for(int i=0;i<m;i++)
    mid=mid->next;
    
    if(count%2==1)
        mid=mid->next;
        
    mid=reverse(mid);
    
    while(mid!=NULL)
    {
        if(head->val==mid->val)
            {
                head=head->next;
                mid=mid->next;
            }
        else
            return 0;
    }
    return 1;
}
