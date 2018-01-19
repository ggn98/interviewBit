int Solution::findMedian(vector<vector<int> > &A) 
{
    int rows=A.size();
    int columns=A[0].size();
    int min=INT_MIN,max=INT_MAX;
    for(int i=0;i<rows;i++)
    {
        if(A[i][0]<min)
        {
            min=A[i][0];
        }
        if(A[i][columns-1]>max)
        {
            max=A[i][columns-1];
        }
    }
    int totalNoToBeSmallerThanMid=(1+rows*columns)/2; //number of elements equal to the median and less than median
    while(min<max) // while(min!=max)
    {
        int mid=(min+max)/2;
        int count=0;
        for(int i=0;i<rows;i++)
        {
            count+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();//gives count of elements maller than equal to mid in each row
        }
        if(count<totalNoToBeSmallerThanMid)
        min=mid+1;
        else // the mid which satisfies, may or may not be present in matrix ,hence we do not return direectly
        max=mid; //instead we update max to mid, min or max returned finally would always be present in the matrix
    }
    //return min or max , as this return statement is executed when min=max , in each case min=max , as ans exists always
    return max; // or return min
}
// https://www.youtube.com/watch?v=BpETOGNqKmo -> for full explaination , thanks to this guy ! :)
