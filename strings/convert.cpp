string Solution::convert(string A, int B) 
{
    if(B==1)
    return A;
    string ans;
    string arr[B];
    for(int i=0;i<B;i++)
        arr[i]="";
    int flag=0;
    int row=0;
    for(int i=0;i<A.length();i++)
    {
        arr[row]+=A[i];
        
        if(row==0)
            flag=0;
        else if(row==B-1)
            flag=1;
            
        if(flag==0)
            row++; //go down 
        else if(flag==1)
            row--; // go up
    }
    for(int i=0;i<B;i++)
        ans+=arr[i];
    return ans;
}