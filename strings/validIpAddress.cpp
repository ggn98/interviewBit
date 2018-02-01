vector<string> Solution::restoreIpAddresses(string s) 
{
    vector<string> res;
    string ans;
    for(int i=1;i<=3;i++) //LENGTH i BEFORE DOT 1
    for(int j=1;j<=3;j++) //LENGTH j BEFORE DOT 2
    for(int k=1;k<=3;k++) //LENGTH k BEFORE DOT 3
    for(int l=1;l<=3;l++) //LENGTH l BEFORE DOT 4
    {
        if(i+j+k+l==s.length()) //when total string is covered
        {
            int A=stoi(s.substr(0,i)); // till dot 1
            int B=stoi(s.substr(i,j)); //till dot 2 
            int C=stoi(s.substr(i+j,k)); //till dot 3
            int D=stoi(s.substr(i+j+k,l)); //till dot 4
            
            if(A<=255 && B<=255 && C<=255 && D<=255)
            {
                ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D);
                if(ans.length()==s.length()+3) // since stoi of "003" gives 3 , therefore
                res.push_back(ans);
            }
        }
    }
    return res;
}
