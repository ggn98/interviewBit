/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* head, int B) 
{
    ListNode* largerHead=NULL;
    ListNode* largerTail=NULL;
    ListNode* smallerHead=NULL;
    ListNode* smallerTail=NULL;
    ListNode* current=head;
    ListNode* next1;
    while(current!=NULL)
    {
        next1=current->next;
        current->next=NULL;
        
        if(current->val>=B)
        {
          if(largerHead==NULL&&largerTail==NULL)
          {
              largerHead=current;
              largerTail=current;
          }
          else
          {
              largerTail->next=current;
              largerTail=largerTail->next;
          }
        }
        
        else
        {
          if(smallerHead==NULL&&smallerTail==NULL)
          {
              smallerHead=current;
              smallerTail=current;
          }
          else
          {
              smallerTail->next=current;
              smallerTail=smallerTail->next;
          }
        }
        
        current=next1;
    }
    if(smallerTail!=NULL)
    {
      smallerTail->next=largerHead;
      return smallerHead;  
    }
    else return largerHead;
}
