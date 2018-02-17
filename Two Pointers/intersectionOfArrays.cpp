vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) 
{
    vector<int> result;
    int start1=0,start2=0;
    while( start1<A.size()&&start2<B.size() )
    {
        if(A[start1]<B[start2])
        {
            start1++;
        }
        else if(A[start1]>B[start2])
        {
            start2++;
        }
        else
        {
            result.push_back(A[start1]);
            start1++;
            start2++;
        }
    }
    return result;
}
