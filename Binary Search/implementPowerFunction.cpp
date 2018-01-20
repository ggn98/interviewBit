
int Solution::pow(int x, int n, int d) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(x<0)
    {
        
    }
    if(n==0)
    {
        if(x==0)
        return 0;
        else
        return 1;
    }
    else if (n%2==0)
    {
        long long y=pow(x,n/2,d);
        long long ans= (y*y)%d;
        if(ans<0)
        {
            return (ans+d)%d;
        }
        else 
        return ans;
    }
    else
    {
        long long y=pow(x,n-1,d);
        long long ans= ((x%d)*y)%d;
        if(ans<0)
        {
            return (ans+d)%d;
        }
        else 
        return ans;
    }
}
// use of property that (ab)mod(m)=((a mod(m))*(b mod(m)))mod(m)