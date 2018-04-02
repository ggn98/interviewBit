/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    ListNode* temp1=A;
    ListNode* temp2=B;
    
    ListNode* head=NULL;
    ListNode* tail=NULL;
    
    int carry=0;
    
    while(temp1!=NULL&&temp2!=NULL)
    {
        int data=temp1->val+temp2->val+carry;
        carry=0;
        
        if(data>9)
            {
                carry=1;
                data=data%10;
            }
        
        ListNode* node=new ListNode(data);
        
        if(head==NULL&&tail==NULL)
        {
            head=node;
            tail=node;
        }
        else
        {
            tail->next=node;
            tail=tail->next;
        }
        
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(carry==1&&temp1==NULL&&temp2==NULL)
    {
       ListNode* node=new ListNode(carry);
       tail->next=node;
       node->next=NULL;
       return head;
    }
    
    if(temp1!=NULL)
    {
        
    while(temp1!=NULL)
    {
        int data=temp1->val+carry;
        carry=0;
        if(data>9)
            {
                carry=1;
                data=data%10;
            }
        ListNode* node=new ListNode(data);
        
        tail->next=node;
        tail=tail->next;
        
        temp1=temp1->next;
    }
    
    if(carry==1)
    {
       ListNode* node=new ListNode(carry);
       tail->next=node;
       node->next=NULL;
    }
    return head;
    }
    else
    {
        while(temp2!=NULL)
        {
        int data=temp2->val+carry;
        carry=0;
        if(data>9)
            {
                carry=1;
                data=data%10;
            }
        ListNode* node=new ListNode(data);
        
        tail->next=node;
        tail=tail->next;
        
        temp2=temp2->next;
        }
       if(carry==1)
       {
       ListNode* node=new ListNode(carry);
       tail->next=node;
       node->next=NULL;
       }
      return head;  
    }
}
