vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) 
{
    int n=A[0].size();
    vector<vector<int> > ans;
    vector<int> *v=new vector<int>[(2*n)-1]; //total no of vectors in answer
    int start=0; // starting of vector arr v
    int count=0; //total number of elements added
    int sum=0; //sum of row+column is constant , initially = 0
    while(count!=n*n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+j==sum)
                {
                    v[start].push_back(A[i][j]);
                    count++;
                }
            }
        }
        sum++;
        start++;
    }
    for(int i=0;i<2*n-1;i++)
    {
        ans.push_back(v[i]);
    }
    return ans;
}