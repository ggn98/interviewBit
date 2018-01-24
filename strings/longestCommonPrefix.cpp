string Solution::longestCommonPrefix(vector<string> &A) 
{
    string result;
    int j=-1,min=INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        if(A[i].length()<=min)
        {
            j=i;
        }
    }
    string smallest=A[j]; // find the smallest string
    A.erase(A.begin()+j); //delete it from the input vector
    int k;
    for(int i=0;i<smallest.length();i++)
    {
        k=0;
        for(k=0;k<A.size();k++)
        {
            if(A[k][i]!=smallest[i]){
                break;
            }
        }
        if(k!=A.size())
        {
            return result; // will reach here , even when 1 of the strings in vector does not have , same iTh char as that of smallest
        }
        else
        {
            result+=smallest[i]; //add ith char of smallest string to result , when all the strings in the vector , have same ith character
        }
    }
}
