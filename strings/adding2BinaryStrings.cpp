string Solution::addBinary(string A, string B) 
{
    if(A.length()<B.length())
    {
        return addBinary(B,A); 
    }
    int carry=0;
    string result;
    int comp1=A.length()-1;
    int comp2=B.length()-1;
    while( comp2>=0 )
    {
        if((A[comp1]=='0'&&B[comp2]=='1')||(A[comp1]=='1'&&B[comp2]=='0'))
        {
            if(carry==0)
                result+="1";
            else
            {
                result+="0";
                carry=1;
            }
            comp1--;
            comp2--;
        }
        else if (A[comp1]=='0'&&B[comp2]=='0')
        {
            if(carry==0)
                result+="0";
            else
            {
                result+="1";
                carry=0;
            }
            comp1--;
            comp2--;
        }
        else if (A[comp1]=='1'&&B[comp2]=='1')
        {
            if(carry==0)
            {
                result+="0";
                carry=1;
            }
            else
            {
                result+="1";
                carry=1;
            }
            comp1--;
            comp2--;
        }
    }
    if(comp1==-1&&comp2==-1)
    {
        if(carry==1)
        {
            result+="1";
            reverse(result.begin(),result.end());
            return result;
        }
    }
    for(int i=comp1;i>=0;i--)
    {
        if(A[i]=='0')
        {
            if(carry==0)
            {
                result+="0";
            }
            else
            {
                result+="1";
                carry=0;
            }
        }
        else
        {
            if(carry==0)
            {
                result+="1";
            }
            else
            {
                result+="0";
                carry=1;
            }
        }
    }
    if(carry==1)
    {
        result+="1";
    }
    reverse(result.begin(),result.end());
    return result;
}