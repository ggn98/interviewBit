int Solution::uniquePaths(int A, int B) 
{
    A=A-1;
    B=B-1;
    int arr[A+1][B+1];
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            if(i==0||j==0)
                arr[i][j]=1;
            else
                arr[i][j]=0;
        }
    }
    for(int i=1;i<=A;i++)
    {
        for(int j=1;j<=B;j++)
        {
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    return arr[A][B];
}