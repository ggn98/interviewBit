bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    bool b=true;
    int j=0;
    for(int i=K;i<arrive.size()&&b==true;i++)
    {
            int flag=0;
            if(depart[j]<=arrive[i])
                {
                    flag=1;
                    j++;
                }
            if(flag==0)
            {
                b=false;
                return b;
            }
    }
    return b;
}