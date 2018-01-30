int Solution::lengthOfLastWord(const string A) 
{
    int spaces=0,count=0,temp=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==32)
        {
            if(count!=0)
                temp=count;
            count=0;
        }
        else
        {
            count++;
            temp=count;
        }
    }
    return temp;
}