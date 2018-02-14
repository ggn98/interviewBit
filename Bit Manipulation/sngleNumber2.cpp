int Solution::singleNumber(const vector<int> &A) 
{
    int res=0,x,sum;
    for(int i=0;i<32;i++)
    {
        sum=0;
        
        x= (1<<i) ; // to get the status of ith bit , we use this mask
        
        for(int j=0;j<A.size();j++)
        {
          if(A[j]&x) //if not =0 then means ith bit is set
          {
            sum++;
          }
        }
        
        if(sum%3) //means ith bit of res is set = 1 
        {
            res=res|x;
        }
    }
    return res;
}
