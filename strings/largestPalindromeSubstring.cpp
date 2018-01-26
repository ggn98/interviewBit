string Solution::longestPalindrome(string A) 
{
    int maxLength=1,high,low,start=0;
    for(int i=1;i<A.length();i++)
    {
        low=i-1; // finding palindromes with i-1 & i as center (even length palindromes)
        high=i;
        while(low>=0&& high<A.length() && A[low]==A[high]) 
        {
            if(high-low+1>maxLength)
            {
                maxLength=high-low+1;
                start=low;
            }
            low--;
            high++;
        }

        low=i-1; // finding palindromes with i-1 & i+1 as center (odd length palindromes)
        high=i+1;
        while(low>=0 && high<A.length() && A[low]==A[high]) 
        {
            if(high-low+1>maxLength)
            {
                maxLength=high-low+1;
                start=low;
            }
            low--;
            high++;
        }
    }
    if(maxLength==1) //return 1st char if no palindrome
    {
        string result(1,A[0]);
        return result;
    }
    string result;
    result=A.substr(start,maxLength);
    return result;
}