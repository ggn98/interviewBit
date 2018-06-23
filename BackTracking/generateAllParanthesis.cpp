void util(vector<string> &result,string res,int n,int m)
{
    if(n==0&&m==0)
    {
        result.push_back(res);
        return;
    }
    if(n>0)
    {
        util(result,res+"(",n-1,m+1);
    }
    if(m>0)
    {
        util(result,res+")",n,m-1);
    }
}

vector<string> Solution::generateParenthesis(int A) {
   vector<string> result;
   util(result,"",A,0);
   sort(result.begin(),result.end());
   return result;
}
