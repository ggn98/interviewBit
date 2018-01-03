void Solution::setZeroes(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    int i,j;
    int row1=0,col1=0;
    for(i=0;i<n;i++)
    {
        if(A[0][i]==0)
        {
            row1=1;
            break;
        }
    }
    for(i=0;i<m;i++)
    {
        if(A[i][0]==0)
        {
            col1=1;
            break;
        }
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(A[i][j]==0)
            {
                A[0][j]=0;
                A[i][0]=0; //indicates that in this row/col a 0 is present
            }
        }
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(A[i][0]==0||A[0][j]==0)
            {
                A[i][j]=0;
            }
        }
    }
    if(row1==1)
    {
        for(i=0;i<n;i++)
        {
            A[0][i]=0;
        }
    }
    if(col1==1)
    {
        for(i=0;i<m;i++)
        {
            A[i][0]=0;
        }
    }
}
