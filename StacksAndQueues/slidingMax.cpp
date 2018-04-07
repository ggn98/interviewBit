vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    deque<int> q;
    vector<int> result;
    int i=0;
    while(i<B)
    {
        //if element pointed by the last of deque is smaller than current elelent in window
        //then it means that this element cant be the maximum element in this window and any other subsequent window
        //hence pop such index from deque
        while(q.empty()!=true&&A[i]>=A[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        i++;
    }
    result.push_back(A[q.front()]);
    //i denotes the current end of a window
    while(i<A.size())
    {
        if(i-q.front()>=B) //if the current end-front at deque , is >= B ,
        {           //then it means we have to remove the front from the deque as it is not in our window anymore
            q.pop_front();
        }
        while(q.empty()!=true&&A[i]>=A[q.back()])
        {
            q.pop_back(); //as it is smaller than current element A[i], hence cant be maximum element of any window
        }
        q.push_back(i);
        //front of deque points to the maximum element
        result.push_back(A[q.front()]);
        i++;
    }
    return result;
}
