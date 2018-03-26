/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head, int k) 
{
    if(k==1)
        return head;
    ListNode *prev=NULL,*current=head,*next;
    int count=0;
    while(current!=NULL&&count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL) //Linked List is not finished , i.e while exits due to count , if current null , then next also null
        head->next=reverseList(next,k); // since now head is the element at last after reversing k times
    return prev; //prev is the head of reversed list
}
