/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int start, int end) 
{
      
    ListNode* newHead=new ListNode(0);
    newHead->next=head;
    
    ListNode* previous=newHead;
    
    for(int i=0;i<start-1;i++)
        previous=previous->next; // it points to node , just before the start node
        
    ListNode* current=previous->next; //points to the start node
    
    for(int i=0;i<(end-start);i++) //no of times we need to move elements in front=END-START
    {
        ListNode *move=current->next; //this is the element to be moved in front of element which is next to the node pointed by previous
        current->next=move->next; //now next of current points to the element , which will be moved forward in next iteration
        move->next=previous->next; //we make move to point to the element , which is next to previous , as we have to move MOVE infront of it
        previous->next=move; //now we have moved move int the front , hence the element just before the start , now points to this new move node.
    }
    
    return newHead->next;
}
/* What we do is we push the elements in front each time so that after required no of operations that portion
is reversed . ex -> 1->2->3->4->5->6->7 , if we want to reverse the portion from 3 to 5 , then what we do is 
we first make 4 before 3 and then 5 before 5 , so that we reverse the portion
Hence no of operations required will be End-Start , ex-5-3=2
we require 2 forward push of 4 and then 5.
Now dummy head , what if we want to reverse 1 to 4 ,then in that case our head would change , 
hence newHead->next points to the head after operation is done. /*