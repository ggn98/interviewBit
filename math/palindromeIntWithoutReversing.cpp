int NumAtIthPos(int A,int i) //find the digit at iTh position
{
    int ans,x;
    int y=A;
    if(i==0)
        x=0;
    else
        x=pow(10,i);
    if(i==0)
    {
        while(y>x)
        {
        ans=y%10;
        y=y/10;
        }
    }
    else
    {
       while(y>=x)
        {
        ans=y%10;
        y=y/10;
        }
    }
    return ans;
}
int Solution::isPalindrome(int n) 
{
    if(n<0)
        return 0;
    int x=n,count=0;
    while(x!=0)
    {
        x=x/10;
        count++;
    }
    int start=0,end=count-1;
    while(start<end)
    {
        int startDigit=NumAtIthPos(n,start);
        int endDigit=NumAtIthPos(n,end);
        if(startDigit==endDigit)
        {
            start=start+1;
            end=end-1;
        }
        else
            return 0;
    }
    return 1;
}
//this is without reversing the original no, passes all the test cases.