void Solution::nextPermutation(vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int max=INT_MAX,i,j,pos=-1;
    for(i=a.size()-2;i>=0;i--)
    {
        for(j=i+1;j<a.size();j++)
        {
            if(a[j]>=a[i]&&a[j]<=max)
            {
                max=a[j];
                pos=j;
            }
        }
        if(pos!=-1)
        break;
    }
    swap(a[i],a[pos]);
    sort(a.begin()+i+1,a.end());
}
