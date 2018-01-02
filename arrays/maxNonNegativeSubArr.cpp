vector<int> Solution::maxset(vector<int> &a) 
{
    long long sum=0,maxSum=INT_MIN;
    int i,j,start=0,end=0,s=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>=0)
        {
            sum=sum+a[i];
            if(sum>maxSum)
                {
                    maxSum=sum;
                    start=s;
                    end=i;
                }
            else if(sum==maxSum)
            {
                if(i-s>end-start)
                {
                    start=s;
                    end=i;
                }
            }
        }
        else
        {
            sum=0;
            s=i+1;
        }
    }
    vector<int> ans;
    if(a[start]<0)
    return ans;
    for(int i=start;i<=end;i++)
        ans.push_back(a[i]);
    return ans;
}