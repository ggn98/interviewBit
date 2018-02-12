unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int pos=31;
    unsigned int rev=0;
    while(A>0&&pos>=0)
    {
        if(A&1)
        {
            rev=rev|(1<<pos);
        }
        A=A>>1;
        pos--;
    }
    return rev;
}
// 1 0 1 1
// 1 is the 3st bit, 0 is the 2nd , 1 1st and then 1 is 0th , unlike vectors
// Now if 0th bit of A is one , what we do is we left shift 1 by value eqaul to pos , which is initially = 31(int size)
// Then we drop the rightmost bit i.e the above checked bit , by rightShift
// and we decrement position