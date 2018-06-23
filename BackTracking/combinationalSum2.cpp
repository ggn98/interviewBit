void util(vector<int> &A, int target, vector<vector<int> > &result,vector<int> &row,int index)
{
    if(target==0)
    {
        result.push_back(row); //we have our answer in row push it in result
        return;
    }
    for(int i=index;i<A.size();i++)
    {
        if(target-A[i]>=0) //A[i] is a candidate
        {
            row.push_back(A[i]);
            util(A,target-A[i],result,row,i+1); //find the possible result with A[i] as element , next element could be from i position as repetition is allowed
            row.pop_back();//now remove this candidate as we have found all the possible solution of this candidate
        }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int target) {
    vector<vector<int> > result;
    vector<int> row;
    
    sort(A.begin(), A.end());
    
    util(A,target,result,row,0);
    
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++)
    {
        for(int j=i+1;j<result.size();j++)
        {
            if(result[j]==result[i])
            {
                result.erase(result.begin()+j);
                j--;
            }
        }
    }
    return result;
}
