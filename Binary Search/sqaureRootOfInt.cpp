int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==0||A==1)
    return A;
    long long start=1,end=A,ans=0;
    while(start<=end)
    {
        long long mid=(start+end)/2;
        if(mid*mid==A) //perfect square
        return mid;
        if(mid*mid < A) //if square of mid is less , then this mid might be the ans as we need 
        {               //floor value of sqrt . ex-12's sqrt is 3.46 , if we find 3 , then we search
                        //for value which is more than 3, if no suchvalue then ans is 3.
            start=mid+1;
            ans=mid;
        }
        else
        {
            end=mid-1; //if sqrt is more then it cant be the answer in any case , hence end=mid-1
        }
    }
    return ans;
}
