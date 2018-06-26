/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode*,RandomListNode*> myMap;
    RandomListNode* p=A;
    while(p)
    {
        myMap[p]=new RandomListNode(p->label);
        p=p->next;
    }
    p=A;
    while(p)
    {
        //LHS returns the required node , as in map lhs and rhs are same 
        //only diff is that RHS is newCopy not existong one
        myMap[p]->next=myMap[p->next];
        myMap[p]->random=myMap[p->random];
        p=p->next;
    }
    return myMap[A];
}
