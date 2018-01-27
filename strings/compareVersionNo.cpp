string trim(string A) //remove leading zeroes
{                     // 1.11.002 & 1.11.2 are same    
    int m=A.length();
    int i=0;
    string temp="";
    while(i<m&&A[i]=='0')
    {
        i++;
    }
    if(i==m)
    {
        temp+="0";
    }
    else
    {
        for(;i<m;i++)
        {
            temp+=A[i];
        }
    }
    return temp;
}
string number(int &i,string A) //finds no before a dot and remove leading zeroes 
{                              //returns a string containing no before the dot , without leading zeroes    
    string temp="";
    while(i<A.length()&&A[i]!='.')
    {
        temp+=A[i];
        i++; 
    }
    //since i is by refernce , after each call to this function , i goes to . position
    return trim(temp);
}
int Solution::compareVersion(string A,string B)
{
    int i=0,j=0;
    string number1,number2;
    while(i<A.length() || j<B.length()) //runs till both are false
    {
        number1=number(i,A);
        i++; //since after execution of number(), i is at position of dot , hence i++
        number2=number(j,B);
        j++; //since after execution of number(), j is at position of dot , hence j++
        
        if(number1.length()==number2.length()) // same length without leading zeroes
        {
            if(number1>number2) 
            {
                return 1;
            }
            else if(number1<number2)
            {
                return -1;
            }
        }
        else //unequal length
        {
            if(number1.length()>number2.length()) // means 1st number is greater as no ;eading zeroes in numbers
            {
                return 1;
            }
            else return -1;
        }
    }
    // out of while loop when both are exactly equal
    return 0;
}