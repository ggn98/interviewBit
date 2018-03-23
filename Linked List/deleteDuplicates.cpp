/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) 
{
    ListNode *dummy=new ListNode(0);
    dummy->next=head;
    ListNode *prev=dummy;
    ListNode *current=head;
    while(current!=NULL)
    {
        while(current->next!=NULL&& current->next->val==current->val )
            current=current->next; //hence current holds the last repeated element of a number
        //if no duplicates , then next lement of previous is current , hence we update previous to current
        if(prev->next==current)
            prev=prev->next;
        else
        {
            prev->next=current->next; //since current repeats , and current presently have last repeated node of a given no hence the next element of curr is pointed by prev
        }
        current=current->next; // update the currrent element with each iteration
    }
    head=dummy->next;
    return head;
}
//attach a dummy head to handle case if starting element repeats , then dummy->next would hold new head

