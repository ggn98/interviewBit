/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;
    ListNode* head;
    if(A->val<=B->val)
    {
        head=A;
        head->next=mergeTwoLists(A->next,B);
    }
    else
    {
        head=B;
        head->next=mergeTwoLists(B->next,A);
    }
    return head;
}
