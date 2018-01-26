bool findNo(char ch)
{
    if(ch>='0'&&ch<='9')
    {
        return true;
    }
    return false;
}
int Solution::atoi(const string A) {
    int count=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==32)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    int start=0,sign=1;
    if(count!=0)
    {
        start=count-1;
    }
    if(A[start]=='-')
    {
        sign=-1;
        start++;
    }
    if(A[start]=='+')
    {
        sign=1;
        start=1;
    }
    long long res=0;
    for(int i=start;i<A.length();i++)
    {
        if(findNo(A[i])==true)
        {
            res=res*10+(A[i]-'0');
        }
        else
        {
            return sign*res;
        }
        if(res>INT_MAX&&sign==1)
        {
            return INT_MAX;
        }
        if(res>INT_MAX&&sign==-1)
        {
            return INT_MIN;
        }
    }
    return sign*res;
}