void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start1=0,start2=0;
    vector<int> result;
    while(start1<A.size()&&start2<B.size())
    {
        if(A[start1]<B[start2])
        {
            result.push_back(A[start1]);
            start1++;
        }
        else
        {
           result.push_back(B[start2]);
           start2++; 
        }
    }
    while(start1<A.size())
    {
        result.push_back(A[start1]);
        start1++;
    }
    while(start2<B.size())
    {
        result.push_back(B[start2]);
        start2++;
    }
    A=result;
}
