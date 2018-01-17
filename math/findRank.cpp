
int Solution::findRank(string A) 
{
    bool charArr[123]={false}; //123 size since Ascii value of z=122
    for(int i=0;i<A.size();i++)
    {
        charArr[A[i]]=true; // make that char true which occur in string
    }
    long int fact[A.size()]; // max fact needed is of A.size()-1
    fact[0]=1;
    for(int i=1;i<A.size();i++)
    {
        fact[i]=(i*fact[i-1])%1000003; //make factorial array
    }
    long int res=1;
    for(int i=0;i<A.size();i++)
    {
        long int count=0;
        for(int j=0;j<A[i];j++)
        {
            if(charArr[j]==true) 
            {
              count++; //count no of number of characters which are smaller than A[i] char
            }
        }
        charArr[A[i]]=false; //make current false , as in next char , we can't use this character
        res+=(count*fact[A.size()-1-i])%1000003;
    }
    return res%1000003;
}