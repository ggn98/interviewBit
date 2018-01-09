vector<int> Solution::primesum(int n) 
{
    vector<bool> val;
    vector<int> ans;
    for(int i=0;i<=n;i++)
    {
        val.push_back(true);
    }
    for(int i=2;i*i<=n;i++) //sieve completes till i reaches root n . 
    {
        if(val[i]==true)
        {
            for(int j=2*i;j<=n;j=j+i)
            {
                val[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(val[i]==true)
        {
            if(val[n-i]==true)
            {
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }
    }
    return ans;
}
