string Solution::multiply(string s1, string s2) 
{
    int n1=s1.size();
    int n2=s2.size();
    if(n1==0||n2==0)
        return "0";
    vector<int> result(n1+n2,0);
    int pos1=0,pos2;
    for(int i=n1-1;i>=0;i--)
    {
        int carry=0;
        int num1=s1[i]-'0';
        pos2=0;
        for(int j=n2-1;j>=0;j--)
        {
            int num2=s2[j]-'0'; 
            int sum=(num1*num2)+result[pos1+pos2]+carry;
            carry=sum/10;
            result[pos1+pos2]=sum%10;
            pos2++;
        }
        if(carry>0)
        {
            result[pos1+pos2]=carry; //since it was initally 0
        }
        pos1++;
    }
    string ans;
    int i=result.size()-1;
    while(i>=0&&result[i]==0)
    {
        i--;
    }
    if(i==-1)
        return "0";
    while(i>=0)
    {
        ans+=to_string(result[i]);
        i--;
    }
    return ans;
}
