int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    int diff=INT_MAX;
    int i=0,j=0,k=0;
    while(i<A.size() && j<B.size() && k<C.size() )
    {
        //Lets assume that A[i],B[j],C[k] be the 3 selected closest elements 
        //now we have to find the maximum difference between these and try to minimize it
        int MAX=max(A[i],max(B[j],C[k]));
        int MIN=min(A[i],min(B[j],C[k]));
        //we store the maximum possible difference in the diff variable
        //MAX-MIN is the largest gap between the 3 arrays
        //as we have to minimize this largest gap , we increment the array which has MIN value in it
        //if we increment array with max or 2nd max value , then it would potentially increase the difference
        //hence we find array having MIN in it and then increment position in that array ! 
        if(MAX-MIN<diff)
        {
           diff=MAX-MIN; //contains maximum difference , between the 3 closest elements . 
        }
        if(A[i]==MIN)
            i++;
        else if(B[j]==MIN)
            j++;
        else
            k++;
    }
    return diff;
}
