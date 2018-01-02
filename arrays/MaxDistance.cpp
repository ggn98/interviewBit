bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}
int Solution::maximumGap(const vector<int> &a) {
    if(a.size()==1)
    return 0;
    vector< pair<int,int> > input;
    for(int i=0;i<a.size();i++)
    {
        pair<int,int> p=make_pair(a[i],i);
        input.push_back(p);
    }
    sort(input.begin(),input.end(),comp);
    int maxDif=-1;
    vector<int> index;
    for(int i=0;i<a.size();i++)
        index.push_back(input[i].second);
    int *maxIndex=new int[a.size()];
    int maxIn=INT_MIN;
    for(int i=a.size()-1;i>=0;i--)
    {
        maxIn=max(maxIn,index[i]);
        maxIndex[i]=maxIn;
    }
    int ans=0;
    for(int i=0;i<a.size()-1;i++)
    {
        if(maxIndex[i+1]>index[i]&&maxIndex[i+1]-index[i]>ans)
        {
            ans=maxIndex[i+1]-index[i];
        }
    }
    return ans;
}