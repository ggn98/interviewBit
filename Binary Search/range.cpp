int lastOccurrence(const vector<int> &A, int B)
{
    int start=0,end=A.size()-1,ans=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(A[mid]==B)
        {
            ans=mid;
            start=mid+1;
        }
        else if(A[mid]<B)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}
int firstOccurrence(const vector<int> &A, int B)
{
    int start=0,end=A.size()-1,ans=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(A[mid]==B)
        {
            ans=mid;
            end=mid-1;
        }
        else if(A[mid]<B)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start=firstOccurrence(A,B);
    int end=lastOccurrence(A,B);
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}
