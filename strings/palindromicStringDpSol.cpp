
string Solution::longestPalindrome(string A) 
{
    int n=A.length();
    bool dp[n][n]; // depicts that a substring from i to j is a palindromic substring or not
    memset(dp, 0, sizeof(dp));
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=false;
        }
    }*/
    int maxLengthOfPalindromincSubstring=1,startOfResult=-1;
    //since all substrings of len=1 are palindromic 
    for(int i=0;i<n;i++)
    {
        dp[i][i]=true; //substring from i to i is a palindromic substring
    }
    //check substring of len=2
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            dp[i][i+1]=true;
            maxLengthOfPalindromincSubstring=2;
            startOfResult=i;
        }
    }
    //loop for length of required palindromic substring of length 3 or more
    for(int k=3;k<=n;k++)
    {
        //now run loop for start position of substring which has a length k
        for(int i=0;i<n-k+1;i++) // +1 because we have to count the considered element alse in the length of the string
        {
            int j=i+k-1; //ending index for starting=i and length=k
            if(A[i]==A[j]&&dp[i+1][j-1]==true)
            {
                dp[i][j]=true;
                if(k>maxLengthOfPalindromincSubstring)
                {
                    maxLengthOfPalindromincSubstring=k;
                    startOfResult=i;
                }
            }
        }
    }
    if(maxLengthOfPalindromincSubstring==1)
    {
        string result(1,A[0]);
        return result;
    }
    string result;
    while(result.length()<maxLengthOfPalindromincSubstring)
    {
        result+=A[startOfResult];
        startOfResult++;
    }
    return result;
}
