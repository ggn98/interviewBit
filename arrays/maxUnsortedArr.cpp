vector<int> Solution::subUnsort(vector<int> &a) 
{
    vector<int> ans;
    int n=a.size();
    int start=-1,end=-1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            start=i;
            break;
        }
    }
    if(start==-1)
    {
        ans.push_back(-1);
        return ans;
    }
    for(int i=n-1;i>0;i--)
    {
        if(a[i]<a[i-1])
        {
            end=i;
            break;
        }
    }
    int minElement=a[start],maxElement=a[start];
    for(int i=start+1;i<=end;i++)
    {
        if(a[i]<minElement)
            minElement=a[i];
        else if (a[i]>maxElement)
            maxElement=a[i];
    }
    for(int i=0;i<start;i++)
    {
        if(a[i]>minElement)
        {
            start=i;
            break;
        }
    }
    for(int i=n-1;i>end;i--)
    {
        if(a[i]<maxElement)
        {
            end=i;
            break;
        }
    }
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}