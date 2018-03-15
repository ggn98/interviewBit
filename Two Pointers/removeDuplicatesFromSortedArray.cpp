int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    for(int i=0;i<A.size();i++)
    {
        int j=i+1;
        while(j<A.size()&&A[j]==A[i])
        {
            j++; 
        }
        if(j!=i+1)
            A.erase(A.begin()+i+1,A.begin()+j); //delete all duplicates in one go 
    }
    return A.size();
}
