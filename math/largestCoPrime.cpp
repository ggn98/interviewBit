int gcd(int A, int B) 
{
    if(A==0)
    return B;
    if(B==0)
    return A;
    if(A==B)
    return A;
    if(A>B)
    {
        return gcd(B,A%B);
    }
    if(A<B)
    {
        return gcd(A,B%A);
    }
}
int Solution::cpFact(int A, int B) 
{
    while(gcd(A,B)!=1)
    {
        A=A/gcd(A,B);
    }
    return A;
}
//we have to find the largest co-prime factor of A i.e a factor of A which is co-prime with B
// i.e gcd(factorOfA,B)==1,in each step wh divide A by GCD of A&B as it removes highest factor common 
//in bot A&b , we do this step till the highest common factor of A&b i.e gcd of A&B!=1
//Final answer is A.