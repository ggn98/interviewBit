/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* head) 
{
    if(head==NULL||head->next==NULL)
        return head;
    ListNode* secondHead=head->next;
    head->next=NULL;
    ListNode* reverse=reverseList(secondHead);
    secondHead->next=head;
    return reverse;
}
ListNode* Solution::reorderList(ListNode* head) 
{
    if(head->next==NULL)
        return head;
        
    ListNode *slow=head,*fast=head->next;
    
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    //now slow->next point to mid , we find this mid i.e second head and then break the linked list
    ListNode *head1=head;
    ListNode *head2=slow->next;
    slow->next=NULL; //breaking linked list
    
    head2 = reverseList(head2); //now reversing the linked list starting from head2
    
    ListNode *dummy=new ListNode(0); //dummy head , to ease the while()
    ListNode *current=dummy; // now current element considered points to this
    
    while(head1||head2) // till any one is not null , attach it to current element
    {
        if(head1)
        {
            current->next=head1; //joining current to required element
            current=current->next; //to join the next element on new current , we update current
            head1=head1->next; //as this element is joined , move forward
        }
        if(head2)
        {
            current->next=head2;
            current=current->next;
            head2=head2->next;
        }
    }
    return dummy->next; //points to the new head
}
