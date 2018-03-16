int Solution::nTriang(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int ans=0;
    int n=A.size();
    int mod=pow(10,9)+7;
    if(n==0)
        return ans;
    for(int tail=n-1;tail>1;tail--) //fix a tail , last tail can be at place 2
    {
        int k=tail-1,j=0; //j=0, as start from starting for each tail , make k to be element before tail
        while(j<k)
        {
            if(A[j]+A[k]>A[tail]) // if j+k satisfies then all the j's from j+1 to k-1 will satisfy, as sorted
            {
                ans=(ans+(k-j)%mod)%mod; // hence k-j combinations are possible of k&j
                k--; //now check for other value of k, by decrementing it , as for this k we have found all the answers
            }
            else
            {
                j++; //sum is less , hence increment j
            }
        }
    }
    return ans;
}
