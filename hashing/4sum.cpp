vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int> > result;
    if(A.size()==0)
    {
        return result;
    }
    sort(A.begin(),A.end());
    int i;
    while(i<A.size()-3)
    {
        int j=i+1;
        while(j<A.size()-2)
        {
            int start=j+1;
            int end=A.size()-1;
            while(start<end)
            {
                int sum=A[start]+A[end];
                int requiredSum=B-A[i]-A[j];
                if(sum>requiredSum)
                {
                    end--;
                }
                else if(sum<requiredSum)
                {
                    start++;
                }
                else
                {
                    vector<int> row;
                    row.push_back(A[i]);
                    row.push_back(A[j]);
                    row.push_back(A[start]);
                    row.push_back(A[end]);
                    result.push_back(row);
                    
                    while(start<A.size()&&A[start]==A[start+1])
                        start++;
                    start++;
                    while(end>0&&A[end]==A[end-1])
                        end--;
                    end--;
                }
            }
            while(j<A.size()-2&&A[j]==A[j+1])
                        j++;
            j++;
        }
        while(i<A.size()-3&&A[i]==A[i+1])
                        i++;
            i++;
    }
    return result;
}
