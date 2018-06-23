void util(vector<vector<int>> &v,vector<int> &row,int i,int n,int k)
{
    if(k==0)
    {
        v.push_back(row);
        return;
    }
    if(i==n)
    {
        return ;
    }
    for(int j=i;j<n;j++)
    {
        row.push_back(j+1);
        util(v,row,j+1,n,k-1);
        row.pop_back();
    }
}
vector<vector<int> > Solution::combine(int n,int k) {
    vector<vector<int>> v;
    vector<int> row;
    util(v,row,0,n,k);
    return v;
}