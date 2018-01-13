int Solution::isPalindrome(int n) 
{
    if(n<0)
        return 0;
    int x=n,y=0;
    while(n>0)
    {
        y=y*10+(n%10); //reversing the given number
        n=n/10;
    }
    if(x==y)
    return 1;
    else
    return 0;
}