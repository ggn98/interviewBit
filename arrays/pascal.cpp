vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> > ans(A);
    if(A==0)
    return ans;
    ans[0].push_back(1);
    if(A==1)
        return ans;
    for(int i=1;i<A;i++) //total no of vectors in the ans
    {
        ans[i].push_back(1);
        for(int j=1;j<i;j++) //entries in each vector
        {
            int res=ans[i-1][j-1]+ans[i-1][j];
            ans[i].push_back(res);
        }
        ans[i].push_back(1);
    }
    return ans;
}
