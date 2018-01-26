int Solution::strStr(const string A, const string B) //search start of B
{
    int M=A.length(); //text
    int N=B.length(); //pattern
    for(int i=0;i<=M-N;i++)
    {
        int j;
        for(j=0;j<N;j++)
            if(A[i+j]!=B[j])
                break;
        if(j==N)
        {
            return i;
        }
    }
    return -1;
}