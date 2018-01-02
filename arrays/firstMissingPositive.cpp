#include<algorithm>
int Solution::firstMissingPositive(vector<int> &a) 
{
    sort(a.begin(),a.end()); //in O(nlogn) , will update if come across O(n)
    int pos=-1;
    for(int i=0;i<a.size()&&pos==-1;i++)
    {
        if(a[i]>0)
            pos=i;
    }
    if(pos==-1)
        return 1;
    if(a[pos]!=1)
       return 1;
    int ans=-1;
    for(int j=pos;j<a.size()-1&&ans==-1;j++)
    {
        if(a[j+1]-a[j]!=1)
            ans=a[j]+1;
    }
    if(ans==-1)
        ans=a[a.size()-1]+1;
    return ans;
}