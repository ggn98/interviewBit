int Solution::divide(int numerator, int denominator) 
{
    if((denominator==0)||(numerator==INT_MIN&&denominator==-1)) //since abs(INT_MIN)=INT_MAX+1 , hence in this case ans would ne INT_MAX+1 , out of bounds
    {
        return INT_MAX;
    }
    int sign=((denominator<0)^(numerator<0))? -1:1 ; // 0,1 -> 1 , 1,1 -> 0
    long long num=labs(numerator); // labs - long long version of abs
    long long den=labs(denominator);
    int res=0;
    while(num>=den)
    {
        long long temp=den,multiple=1;
        while(num>=(temp<<1))
        {
            temp=temp<<1;
            multiple=multiple<<1;
        }
        //temp is largest power of 2 and multiple of denominator , which is less than numerator
        //ex for 50/4 in loop 1 , temp=32 (largest power of 2 and multiple of 4 , less than 50)
        //hence update num to num-temp i.e here 50-32=18 , in step 1
        //add the multiple to res
        //continue this till numerator is less than denominator
        num=num-temp; 
        res+=multiple;
    }
    return (sign==1)? res:-res;
}
//Explaination at
//https://leetcode.com/problems/divide-two-integers/discuss/13407/Detailed-Explained-8ms-C++-solution