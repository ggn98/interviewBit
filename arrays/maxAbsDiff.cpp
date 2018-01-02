int Solution::maxArr(vector<int> &x) 
{
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,max4=INT_MIN,ans=INT_MIN;
    for(int i=0;i<x.size();i++)
    {
        max1=max(max1,x[i]+i);
        max2=max(max2,x[i]-i);
        max3=max(max3,-x[i]+i);
        max4=max(max4,-x[i]-i);
    }
    for(int i=0;i<x.size();i++)
    {
        ans=max(ans,max1-x[i]-i);
        ans=max(ans,max2-x[i]+i);
        ans=max(ans,max3+x[i]-i);
        ans=max(ans,max4+x[i]+i);
    }
    return ans;
}