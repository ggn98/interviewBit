string Solution::countAndSay(int A) 
{
    if(A==1)
    {
        return "1";
    }
    string previous=countAndSay(A-1);
    string result;
    vector<bool> b;
    for(int i=0;i<previous.length();i++)
    {
        b.push_back("true");
    }
    for(int i=0;i<previous.length();i++)
    {
        if(b[i]==true)
        {
        int count =1;
        for(int j=i+1;j<previous.length();j++)
        {
            if(previous[j]==previous[i])
            {
                count++;
                b[j]=false;
            }
            else
            {
                break;
            }
        }
        result+=to_string(count);
        result+=previous[i];
        }
    }
    return result;
}