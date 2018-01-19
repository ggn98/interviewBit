int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start=0,end=A.size()-1,ans=-1;
    if(B<A[0])
    return 0;
    if(B>A[end])
    return A.size();
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(A[mid]>=B)
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}