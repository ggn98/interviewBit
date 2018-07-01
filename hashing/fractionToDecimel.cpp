string Solution::fractionToDecimal(int a, int b) 
{
    //make use of long else error , cant figure out why :(
    string res;
    long num = a, den = b; 
    if(num==0)
    return "0";
    if(num<0 ^ den<0)
    {
        res+='-';
    }
    
    num=abs(num);
    den=abs(den);
    
    res+=to_string(num/den); //use to string here as this quotient is of length more than 1 , hence it is not a char but a string
    
    long rem;
    rem=num%den;
    
    if(rem==0)
    return res;
    
    unordered_map<int,int> myMap;
    res+='.';
    
    while(rem!=0)
    {
        if(myMap.find(rem)!=myMap.end())
        {
            res.insert(myMap[rem],1,'(');//at position myMap[rem] i.e from where the answer to this remainder started , insert 1 --> '('
            res+=')';//insert this at end i.e after the place where this reaminder just occured
            return res;
        }
        else
        {
            myMap[rem]=res.length();//as this is the index from which answer to this remainder would start
            rem=rem*10;
            res+='0'+(rem/den); //adds a character hence use '0'+quotient , this quotient(rem/den) is always of one digit
        }
        rem=rem%den;
    }
    return res;
}
