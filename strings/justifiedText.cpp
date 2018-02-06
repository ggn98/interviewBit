vector<string> Solution::fullJustify(vector<string> &A, int B) 
{
    vector<string> ans,vs;
    if(A.size()==0)
    return ans;
    string str;
    int len=0;
    for(int i=0;i<A.size();i++)
    {
        if(len+vs.size()+A[i].size()<=B)
        {
            vs.push_back(A[i]);
            len+=A[i].size();
        }
        else
        {
            if(vs.size()==1)
            {
                str=vs[0];
                str.append(B-str.size(),' ');
                ans.push_back(str);
            }
            else if(vs.size()>1)
            {
                int spacesEach=(B-len)/(vs.size()-1);
                int extraLeftSpaces=(B-len)%(vs.size()-1);
                str=vs[0];
                for(int j=1;j<vs.size();j++)
                {
                    if(j<=extraLeftSpaces)
                        str.append(spacesEach+1,' ');
                    else
                        str.append(spacesEach,' ');
                    str+=vs[j];
                }
                ans.push_back(str);
            }
            vs.clear();
            vs.push_back(A[i]);
            len=A[i].size();
        }
    }
    //last line
    str=vs[0];
    for(int j=1;j<vs.size();j++)
    {
        str+=' '+vs[j];
    }
    str.append(B-str.size(),' ');
    ans.push_back(str);
    return ans;
}
//https://leetcode.com/problems/text-justification/discuss/24965/Easy-understanding-solution leetCode discussion