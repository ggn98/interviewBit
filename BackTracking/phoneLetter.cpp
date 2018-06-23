string mapping(int no)
{
    switch(no)
    {
        case 0:return "0";
        case 1:return "1";
        case 2:return "abc";
        case 3:return "def";
        case 4:return "ghi";
        case 5:return "jkl";
        case 6:return "mno";
        case 7:return "pqrs";
        case 8:return "tuv";
        case 9:return "wxyz";
        default:return "";
    }
}
vector<string> util(vector<string> result,string A,int start,int n)
{
    if(start+1==n)
    {
        string starting=mapping(A[start]-'0');
        for(int i=0;i<starting.length();i++)
        {
            string res(1,starting[i]);
            result.push_back(res);
        }
        return result;
    }
    vector<string> temp=util(result,A,start+1,n);
    string starting=mapping(A[start]-'0');

    for(int i=0;i<starting.length();i++)
    {
        for(int j=0;j<temp.size();j++)
            {
                string res(1,starting[i]);
                res=res+temp[j];
                result.push_back(res);
            }
    }

    return result;
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> result;
    result=util(result,A,0,A.length());
    return result;
}
