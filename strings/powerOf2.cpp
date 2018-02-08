int Solution::power(string A) 
{
    if(A=="0"||A=="1")
    {
        return 0;
    }
    string one="";
    for(int i=1;i<A.length();i++)
    {
        one+='0';
    }
    one+='1';
    while(1)
    {
        if(A==one) //means we have reduced A to 1 
            return 1;
            
        int rem=0;
        for(int i=0;i<A.length();i++)
        {
            int num=A[i]-'0';
            if(rem==1)  // rem will be always , 1 or 0 , as we are dividing by 2.
                num=num+10;
            rem=num%2;
            A[i]=(num/2)+'0'; //convert into a char and store at ith pos
        }
        // not a power , ex-14 , will reduce to 7 and then to 3 with remainder=1 
        if(rem==1)
            return 0;
    }
}
// thanks to Piyush Gupta ! 