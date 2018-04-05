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
