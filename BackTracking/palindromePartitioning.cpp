bool isPalindrome(string A,int start , int end) //both inclsusive
{
    while(start<end)
    {
        if(A[start]!=A[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void util(vector<vector<string> > &result,vector<string> &row,int start,int end,string A)
{
    if(start>=end)
    {
        result.push_back(row);
        return;
    }
    for(int i=start;i<end;i++)
    {
        if(isPalindrome(A,start,i)==true)
        {
            row.push_back(A.substr(start,i-start+1)); //we know that start-->i is a palindrome 
            util(result,row,i+1,end,A); //find all palindrome starting from i+1
            row.pop_back(); //now since we have found all the palindromes from start to i & i+1 to end , 
                            //now pop this element i.e start-->i , 
                            //so that we can find similarly for start-->i+1 & so on.
        } 
    }
    return;
}
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   vector<string> row;
   vector<vector<string> > result;
   util(result,row,0,A.length(),A);
   return result;
}
