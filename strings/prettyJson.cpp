vector<string> Solution::prettyJSON(string A) 
{
    int spaces=0;
    vector<string> result;
    string ans="";
    int flag=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='{'||A[i]=='[')
        {
            
            if(ans!=""&&ans[ans.length()-1]!='\t')  
            result.push_back(ans);
            ans="";
            for(int j=0;j<spaces;j++)
            {
                ans+='\t';
            }
            ans+=A[i];
            result.push_back(ans);
            ans="";
            spaces++;
            for(int j=0;j<spaces;j++)
            {
                ans+='\t';
            }
        }
        else if(A[i]=='}'||A[i]==']')
        {
          if(ans[ans.length()-1]!='\t')  
            result.push_back(ans);
          ans="";
          spaces--;
          for(int j=0;j<spaces;j++)
          {
                ans+='\t';
          }
          ans+=A[i];
          if(i!=A.length()-1)
          {
            if(A[i+1]==',')
                ans+=',';
            flag=1;
          }
          result.push_back(ans);
          ans="";
          for(int j=0;j<spaces;j++)
            {
             ans+='\t';
            }
          }
         else if (A[i]==',')
         {
             if(flag==1)
               {
                   flag=0;
                   continue;
               }
             ans+=A[i];
             result.push_back(ans);
             ans="";
             for(int j=0;j<spaces;j++)
             {
                ans+='\t';
             }
         }
         else
         {
             ans+=A[i];
         }
    }
    return result;
}
