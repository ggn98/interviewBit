bool combine(int a1,int b1) // i+1 & i
{
    string a=to_string(a1);
    string b=to_string(b1);
    string r1=a+b;
    string r2=b+a;
    if(r1>r2)
        return true; //put a1 before b1 as no1 which is ab is large
    else return false;//put b1 before a1 as no2 which is ba is large
}
string Solution::largestNumber(const vector<int> &a) 
{
    vector<int> ans;
    for (int i = 0; i < a.size(); i++) 
    {
        ans.push_back(a[i]);
    }
    sort(ans.begin(),ans.end(),combine);
    string result;
    for(int i=0;i<ans.size();i++)
    {
        string r=to_string(ans[i]);
        result+=r;
    }
    if(ans[0]==0)
        return "0";
    return result;
}