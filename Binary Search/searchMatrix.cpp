int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rows=A.size();
    int columns=A[0].size();
    for(int i=0;i<rows;i++)
    {
        if(A[i][0]<=B&&A[i][columns-1]>=B)
        {
            int start=0; //starting index of a row
            int end=columns-1; //ending index of a row
            while(start<=end)
            {
                int mid=(start+end)/2; //mid is the index of ith row at which we are checking for number
                if(A[i][mid]==B) 
                {
                    return 1;
                }
                else if(A[i][mid]<B)//this means that element we are searching is at more right, hence start=mid+1
                {
                    start=mid+1;
                }
                else//this means that element we are searching is at more left, hence end=mid-1
                {
                    end=mid-1;
                }
            }
        }
    }
    return 0;
}
