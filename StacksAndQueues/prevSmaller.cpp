vector<int> Solution::prevSmaller(vector<int> &A) 
{
    stack<int> s;
    //Stack is used to maintain a subsequence of the values 
    //that have been processed so far and are smaller than 
    //any later value that has already been processed.
    vector<int> res;
    for(int i=0;i<A.size();i++)
    {
        while(s.empty()==false&&s.top()>=A[i])
        {
            s.pop();
        }
        if(s.empty()==true)
        {
            res.push_back(-1);
        }
        else
        {
            res.push_back(s.top());
        }
        s.push(A[i]);
    }
    return res;
}
//AN ELEMENT(SAY X) WHICH ARIVES MUST REMOVE ALL THE ELEMENTS GREATER THAN IT FROM THE STACK AS , THE NEXT ELEMENTS (SAY Y) WOULD SEARCH
//FOR NEAREST SMALLER ELEMENT , HENCE ELEMENTS GREATER THAN THE CURRENT ELEMENT(X) ARE OF NO USE , AS TO FIND THE NEAREST ELEMENT SMALLER 
//THAN Y, IT WOULD BE EITHER THIS ELEMENT(X) OR ELEMENT SMALLER THAN THIS , ELEMENTS GREATER THAN X ARE OF NO USE
//HENCE THOSE WHICH ARE SMALLER THAN CURRENT ELEMENT(X)
//MUST BE KEPT IN THE STACK ALONG WITH X, WHILE GREATER ELEMENTS ( > X) MUST BE REMOVED