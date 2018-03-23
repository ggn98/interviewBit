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
            current=current->next;
        if(prev->next==current)
            prev=prev->next;
        else
        {
            prev->next=current->next;
        }
        current=current->next;
    }
    head=dummy->next;
    return head;
}
//attach a dummy head to handle case if starting element repeats , then dummy->next would hold new head

