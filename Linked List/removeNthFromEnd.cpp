/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int B) 
{
    ListNode* temp=head;
    for(int i=0;i<B&&temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL)
        {
            return head->next; //temp==NULL , means that B is greater than size of linked list , hence omit only the head and return rest of linked list
        }
        
    ListNode* temp2=head;
    while(temp->next!=NULL)
    {
        temp2=temp2->next;
        temp=temp->next;
    }
    temp2->next=temp2->next->next;
    return head;
}
