#include<bitset>
void util(vector<int> &result,bitset<32> &bits,int A)
{
    if(A==0)
    {
        result.push_back(bits.to_ulong());
        return;
    }
    util(result,bits,A-1);
    bits.flip(A-1);
    util(result,bits,A-1);
    return ;
}
vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bitset<32> bits; //all 0 initially
    vector<int> result;
    util(result,bits,A);
    return result;
}
