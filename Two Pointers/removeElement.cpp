int Solution::removeElement(vector<int> &A, int B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //sort( A.begin() , A.end() );
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==B)
            continue;
        else
        {
            A[count]=A[i];
            count++;
        }
    }
    //A.erase(A.begin()+count,A.end()); -----> to erase the undesired elements
    return count;
}
