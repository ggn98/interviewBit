int Solution::trailingZeroes(int A) 
{
    int ans=0;
    for(int i=5;A/i>0;i=i*5)
    {
        ans+=A/i;
    }
    return ans;
}
//a Zero is produced as a result of multiple of 10 i.e multiple of 2&5
//since no of multiples of 2's in factorial is always more or equal to the multiples of 5
//hence we count only the total no of multiples of 5
//why i=i*5?
//ex-> A=100, now multiples of 5 are 100/5=20(step 1), but the thing is next power of 5 i.e 25 also has 
//multiples less than 100, which has one more 5 as factor
//ex 25=5*5, we have counted only one 5 in 1st step , hence to count the additional 5 in multiples of 25
//we do 100/25=4 , i.e 4 more terms are multiples of 25 , 25,50,75,100 all of them contain 2 times 5
//out of which only 1 has been counted.
//Hence we add in total result, do this till A/i>0 . (100/125=0, stop ).