bool isValid(vector<int> &A,int mid,int B)
{
    int students=1,count=0;
    for(int i=0;i<A.size();i++)
    {
        if(count+A[i]>mid)
        {
            count=A[i];
            students++;
            if(students>B)
            return false;
        }
        else
        {
            count+=A[i];
        }
    }
    return true;
}
int Solution::books(vector<int> &A, int B) 
{
    if(B>A.size())
    return -1;
    int start=0,end=0,ans=-1;
    for(int i=0;i<A.size();i++)
    {
        start=max(start,A[i]); // minimum of maximum pages allocated is the book with max pages
        end+=A[i];
    }
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(isValid(A,mid,B)==false)
        {
            start=mid+1;
        }
        else
        {
            ans=mid;
            end=mid-1;
        }
    }
    return ans;
}
