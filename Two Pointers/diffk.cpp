int Solution::diffPossible(vector<int> &A, int B) 
{
    for(int i=0;i<A.size()-1;i++)
    {

    int start=i,end=A.size()-1;
    while(start<end)
    {
        int diff=abs(A[end]-A[start]);
        if(diff==B)
        return 1;
        else if (diff>B)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    
    }
    return 0;
}
