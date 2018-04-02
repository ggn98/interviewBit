/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* head) 
{
    ListNode* sortedHead=NULL;
    ListNode* current=head;
    ListNode *next1;
    ListNode *temp;
    while(current!=NULL)
    {
       next1=current->next; //save the next element
       
       if(sortedHead==NULL||sortedHead->val>=current->val) //if no head or value of head is greeater
       {
           current->next=sortedHead;
           sortedHead=current;
       }
       else
       {
           temp=sortedHead;
           while(temp->next!=NULL&&temp->next->val<current->val) // if we use temp instead of temp->next then ex-1->10->9 , temp would point to 10 , hence we use temp->next->val
           {
               temp=temp->next; //find the position before the insertion point
           }
           current->next=temp->next;
           temp->next=current;
       }
       
       current=next1;
    }
    return sortedHead;
}
