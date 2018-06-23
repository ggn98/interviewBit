void util(vector<vector<int> > &result,vector<int> &row,vector<int> &A,int index,int n)
{
    if(index==n)
    {
        result.push_back(row);
        return;
    }
    for(int i=index;i<n;i++)
    {
        swap(A[index],A[i]);
        row.push_back(A[index]); //or push A[i] before swapping , same thing as this
        util(result,row,A,index+1,n); //call after swapping
        swap(A[index],A[i]);//swap back to nullify effect of swapping as for this i , we have found solution
        row.pop_back();//pop back the present i , so that next i can be inserted at index and we can find solutions for it
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > result;
    vector<int> row;
    int n=A.size();
    util(result,row,A,0,n);
    return result;
}
