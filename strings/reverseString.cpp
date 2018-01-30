void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> ans;
    string temp="";
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==32&&temp!="")
        {
            ans.push_back(temp);
            temp="";
        }
        else
        {
            temp+=A[i];
        }
    }
    if(temp!="")
    ans.push_back(temp);
    A="";
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(i!=0)
        A+=ans[i]+" ";
        else
        A+=ans[i];
    }
}