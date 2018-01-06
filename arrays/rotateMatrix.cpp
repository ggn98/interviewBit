void Solution::rotate(vector<vector<int> > &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=a[0].size();
    for(int i=0;i<(n/2);i++) //total number of cycles 
    {
        for(int j=i;j<n-i-1;j++) //elements in each cycle 
        {
            int temp=a[i][j];
            a[i][j]=a[n-1-j][i]; 
            a[n-1-j][i]=a[n-1-i][n-1-j];
            a[n-1-i][n-1-j]=a[j][n-1-i];
            a[j][n-1-i]=temp;
        }
    }
}