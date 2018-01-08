int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector <bool> v(A.size()); //by default all values are false
    for(int i=0;i<A.size();i++)
    {
        if(!v[A[i]]) //if false make true 
        {
            v[A[i]]=true;
        }
        else
            return A[i]; //if already true then repeating
    }
    return -1; // no repeating
    //this passes the test cases, however it takes i think O(n)
    //will come across the required solution ( if able to understand :P )
}
