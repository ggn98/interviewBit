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
        //temp = multiple * denominator
        num=num-temp; 
        res+=multiple;
    }
    return (sign==1)? res:-res;
}
//Explaination at
//https://leetcode.com/problems/divide-two-integers/discuss/13407/Detailed-Explained-8ms-C++-solution