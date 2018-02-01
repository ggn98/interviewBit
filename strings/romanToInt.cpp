int mapping(char ch)
{
    if(ch=='I')
        return 1;
    if(ch=='V')
        return 5;
    if(ch=='X')
        return 10;  
    if(ch=='L')
        return 50;
    if(ch=='C')
        return 100;
    if(ch=='D')
        return 500;
    if(ch=='M')
        return 1000;
}
int Solution::romanToInt(string A) 
{
    int res=mapping( A[A.length()-1] );
    for(int i=A.length()-2;i>=0;i--)
    {
        if( mapping(A[i]) < mapping(A[i+1]) )
            res-=mapping(A[i]);
        else
            res+=mapping(A[i]);
    }
    return res;
}