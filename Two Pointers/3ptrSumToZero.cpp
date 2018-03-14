vector<vector<int> > Solution::threeSum(vector<int> &A) 
{
    sort(A.begin(),A.end());
    vector<vector<int> > ans;
    int n=A.size(),j,k;
    for(int i=0;i<n-2;i++)
    {
        j=i+1;
        k=n-1;
        while(j<k) //k==j , no triplet
        {
            int sum=A[i]+A[j]+A[k];
            if(sum==0)
            {
                vector<int> res;
                res.push_back(A[i]);
                res.push_back(A[j]);
                res.push_back(A[k]);
                ans.push_back(res);
                
                while(A[j]==A[j+1])
                j++;
                while(A[k]==A[k-1])
                k--;
                
                j++; //go to next unique j
                k--; //go to next unique k
            }
            else if (sum>0)
            {
               k--; //dec k
            }
            else 
            {
               j++; //inc j
            }
        }
        while(A[i]==A[i+1]) //go to last repeating i , next ++ in for loop
                i++;
    }
    return ans;
}
