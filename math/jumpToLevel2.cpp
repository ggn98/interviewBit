vector<vector<int> > Solution::prettyPrint(int A) 
{
    int size=2*A-1;
    vector<vector<int> > ans(size,vector<int>(size));
    int center=A-1;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            ans[i][j]=max(abs(i-center),abs(j-center))+1;
        }
    }
    return ans;
}
