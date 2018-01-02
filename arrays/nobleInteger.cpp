
int Solution::solve(vector<int> &a)
{
    sort(a.begin(),a.end());
    int flag=-1;
    for(int i=0;i<a.size()&&flag==-1;i++)
    {
        int count=0;
        int j=i+1;
        while(a[j]==a[i]&&j<a.size())
        {
            count++;
            j++;
        }
        if(a[i]==a.size()-1-i-count)
            flag=1;
    }
    return flag;
}