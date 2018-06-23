int Solution::colorful(int A) 
{
    vector<int> digits;
    while(A)
    {
        digits.push_back(A%10);
        A=A/10;
    }
    unordered_map<long long int,bool> hash;
    for(int i=0;i<digits.size();i++)
    {
        long long int product=1;
        for(int j=i;j<digits.size();j++)
        {
            product=product*digits[j];
            if(hash.find(product)!=hash.end())//i.e it is found already in the map
            {
                return 0;
            }
            hash.insert({product,true});
        }
    }
    return 1;
}
