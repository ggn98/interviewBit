int Solution::titleToNumber(string s) 
{
    int k=0;
    int result=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        int val=s[i]-64;
        result=result+val*pow(26,k);
        k++;
    }
    return result;
}
// ABC is 1*pow(26,2)+2*pow(26,1)+3*pow(26,0)=731