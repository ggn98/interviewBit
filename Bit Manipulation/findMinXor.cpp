int Solution::findMinXor(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int res=INT_MAX;
    for(int i=0;i<A.size()-1;i++)
    {
        int x=A[i]^A[i+1];
        if(x<res)
            res=x;
    }
    return res;
}
//since difference of no of 0s and 1s , would increase as we move forward in the vector
//Hence value of XOR would increase
//Therefore we sort the array first so that , we have to find XOR with just next element only
//Since difference between bits set 0 and bits set 1 b/w the ith and i+1thelement 
//will be least when the array is sorted