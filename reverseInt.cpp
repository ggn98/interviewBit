int Solution::reverse(int n) 
{
    long int ans=0,flag=0;
    if(n<0)
    {
        flag=1;
        n=abs(n);
    }
    while(n>0)
    {
        ans=ans*10+(n%10);
        n=n/10;
    }
    if(ans>INT_MAX)
    return 0;
    if(flag==1)
    {
        ans=ans*-1;
    }
    return ans;
}
