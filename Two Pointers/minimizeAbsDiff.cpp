int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    int a=A.size()-1,b=B.size()-1,c=C.size()-1;
    int temp=1,ans=INT_MAX; //initialize temp with anything greater than 1
    
    while(temp>=0) //temp is the variable having index of element which is lower than maxNum of an array
    {
        int maxNum=max(max(A[a],B[b]),C[c]);
        int minNum=min(min(A[a],B[b]),C[c]);
        
        if(abs(maxNum-minNum)<ans)
            ans=abs(maxNum-minNum); //upadte only if required
        
        //check maxNum is of which array and hence reduce the largest element of that array only
        
        if(maxNum==A[a])
            {
                temp=a-1;
                a=temp;
            }
        else if(maxNum==B[b])
            {
                temp=b-1;
                b=temp;
            }
        else if(maxNum==C[c])
            {
                temp=c-1;
                c=temp;
            }
    }
    return ans;
    //reduce max each time so that difference can be reduced
    //we can also increase min ?
}