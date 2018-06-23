int Solution::trap(const vector<int> &A) 
{
    int n=A.size();
    int left[n];
    int right[n];
    int ans=0;
    
    left[0]=A[0];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],A[i]); // find largest to left of ith builduing
    }
    
    right[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
    {
    right[i]=max(A[i],right[i+1]);  // find largest to right of ith builduing      
    }
    
    for(int i=0;i<n;i++)
    {
        ans+=min(right[i],left[i])-A[i]; //water above this builduing
    }
    
    return ans;
}
