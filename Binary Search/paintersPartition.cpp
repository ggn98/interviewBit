bool isValid(vector<int> &A,int mid,int K,int L)
{
    long long int painters=1,count=0;
    for(int i=0;i<A.size();i++)
    {
        if(count+A[i]>mid)
        {
            count=A[i];;
            painters++;
            if(painters>K)
            return false;
        }
        else
        {
            count+=A[i];;
        }
    }
    return true;
}
int Solution::paint(int K, int L, vector<int> &A) 
{
    int start=0,end=0;
    long long ans=-1;
    for(int i=0;i<A.size();i++)
    {
        start=max(start,A[i]);
        end+=A[i];
    }
    while(start<=end)
    {
        long long mid=(start+end)/2;
        if(isValid(A,mid,K,L)==false)
        {
            start=mid+1;
        }
        else
        {
            ans=mid;
            end=mid-1;
        }
    }
    return (int)((ans*L)%10000003);
}
//same as book allocation
