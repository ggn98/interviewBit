/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int B) 
{
    int count=0;
    ListNode* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(B>=count)
        B=B%count;
    
    if(B==0)
        return head;

    temp=head;
    for(int i=0;i<B;i++)
        temp=temp->next;
    
    ListNode* BthFromEnd;
    
    ListNode* temp2=head;
    while(temp->next!=NULL)
    {
        temp2=temp2->next;
        temp=temp->next;
    }
    BthFromEnd=temp2->next;
    temp2->next=NULL;
    
    temp=BthFromEnd;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head;
    return BthFromEnd;
}
//find Bth from end and then attach head to the end of it .