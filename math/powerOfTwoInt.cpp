int Solution::isPower(int n) 
{
    if(n<=1)
        return 1;
    int size=sqrt(n)+1;
    bool arr[size]; 
    if(n%2==0)
    {
       for(int i=0;i<size;i++) //even no can be expressed in power of even no only
        {
            if(i%2==0)
            {
                arr[i]=true;
            }
            else
            {
                arr[i]=false;
            }
        }
    }
    else
    {
        for(int i=0;i<size;i++) //odd no can be expressed in power of odd no only
        {
            if(i%2==0)
            {
                arr[i]=false;
            }
            else
            {
                arr[i]=true;
            }
        }
    }
    for(int x=2;x<=sqrt(n);x++)
    {
        if(arr[x]==true)
        {
            int ans=x;
            int pow=2;
            while(pow<=32&&ans<n) // for a 32 bit signed int , there is no need to check for
            {                     // power greater than 32 for any value x<=sqrt(n)
                ans=ans*x;
                if(ans==n)
                {
                return 1;
                }
                pow++;
            }
            for(int i=x*x;i<size;i=i*x) // if for x no answer , then no answer of all powers of x < = sqrt(n)
            {
              arr[i]=false;
            }
        }
        else
            continue;
    }
    return 0;
}