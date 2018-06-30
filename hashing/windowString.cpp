string Solution::minWindow(string S, string T) 
{
    int hasFoundTillNow[256];
    int neededToBeFound[256];
    for(int i=0;i<256;i++)
    {
        hasFoundTillNow[i]=0;
        neededToBeFound[i]=0;
    }
    for(int i=0;i<T.length();i++)
    {
        neededToBeFound[T[i]]++;
    }
    int end,minStart,minEnd;
    int minLength=INT_MAX;
    int count=0,start=0;
    for(end=0;end<S.length();end++) //run over whole given string S
    {
        if(neededToBeFound[S[end]]==0)
        {
            continue; //s[end] will point to a char only which is present in T
        }
        hasFoundTillNow[S[end]]++; //increment found count of that character
        
        if(hasFoundTillNow[S[end]]<=neededToBeFound[S[end]]) //if count has not exceeded the needed count , increment the total coinu matched
        {
            count++;
        }
        if(count==T.length()) //if all matched 
        {
            while(neededToBeFound[S[start]]==0 || hasFoundTillNow[S[start]]>neededToBeFound[S[start]]) //2 cases where we have useless char at the start of window
            {
                if(hasFoundTillNow[S[start]]>neededToBeFound[S[start]])
                {
                    hasFoundTillNow[S[start]]--; //decrement the count if any such repeating char at start
                }
                start++; //increment start
            }
            if(minLength>end-start) //check if new solution possible
            {
                minStart=start;
                minEnd=end;
                minLength=end-start;
            }
        }
    }
    if(minLength==INT_MAX)
    return "";
    else
    {
        string result="";
        for(int i=minStart;i<=minEnd;i++)
        {
            result+=S[i];
        }
        return result;
    }
}
