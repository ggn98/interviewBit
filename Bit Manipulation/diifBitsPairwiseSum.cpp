int Solution::cntBits(vector<int> &A) 
{
    long long ans=0;
    int n=A.size();
    for(int i=0;i<32;i++)
    {
        long long count=0;
        
        for(int j=0;j<n;j++)
        {
            if(A[j]&(1<<i))
            {
                count++;
            }
        }
        
        ans+=( count * (n-count) ) * 2;
    }
    return ans%(1000000007);
}