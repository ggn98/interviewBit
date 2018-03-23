/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head) 
{
    if(head==NULL||head->next==NULL)
        return head;
    ListNode* secondHead=head->next;
    head->next=NULL;
    ListNode* reverse=reverseList(secondHead);
    secondHead->next=head;
    return reverse;
}
