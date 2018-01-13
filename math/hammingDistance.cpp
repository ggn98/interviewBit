int Solution::hammingDistance(const vector<int> &A) {
    long ans=0;
    long n=A.size();
    for(int i=0;i<32;i++) //int has 32 bits , hence checking each bit position
    {
        int count=0;
        for(int j=0;j<n;j++) //picking up every no for each bit 
        {
            if( ( A[j]&(1<<i) ) ) //checking whether ith bit of A[j] is set or not
            {
                count++; //if set , count increments 
            }
        }
        ans += (count * (n - count) * 2) ; //n-count total no of non-set bits at bit position i
    }
    return ans% 1000000007;;
}
//ans for ith bit is (noOfSetBits)*(noOfNonSetBits)*2 i.e total permutations possible
//if x is no of set bits and y of on set bits , total possible permutations=x*y, since we have to find 
//for both the pairs ex-{1,2}&{2,1}, therefore we multiply by 2 