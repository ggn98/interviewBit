bool isAlphaNum(char ch)
{
    if((ch>='1'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
    return true;
    return false;
}
int Solution::isPalindrome(string A) 
{
    int start=0,end=A.size()-1;
    while(start<=end)
    {
        if(isAlphaNum(A[start])==false)
        {
            start++;
        }
        if(isAlphaNum(A[end])==false)
        {
            end--;
        }
        if(isAlphaNum(A[start])&&isAlphaNum(A[end]))
        {
            if(abs(A[start]-A[end])==32||A[start]-A[end]==0)
            {
                start++;
                end--;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}
