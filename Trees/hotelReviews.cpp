bool comp(pair<int,int> a,pair<int,int> b) //to sort and preserve order at the same time
{
    if(a.first<b.first)
        return false;
    if(a.first==b.first)
    {
        return a.second<b.second; //if same then return according to the index
                                  //if index of a is smaller return true i.e put a before b
                                  //else put b before a , if it returns false
    }
    else return true;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    map<string,bool> goodWord;
    string s="";
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='_'||i+1==A.length())
        {
            if(i+1==A.length())
                s=s+A[i];
            goodWord[s]=true;
            s="";
        }
        else
        {
            s=s+A[i];
        }
    }
    vector< pair<int,int> > counts;
    for(int i=0;i<B.size();i++)
    {
        //extract goodWords from each string in vector
        int count=0;
        string s1="";
        for(int j=0;j<B[i].length();j++)
        {
            if(B[i][j]=='_'||j+1==B[i].length())
                {
                    if(j+1==B[i].length())
                        s1=s1+B[i][j];
                    if(goodWord.find(s1)!=goodWord.end())//found
                    {
                        count++;
                    }
                    s1="";
                }
            else
                {
                    s1=s1+B[i][j];
                }
        }
        counts.push_back(make_pair(count,i));
    }
    sort(counts.begin(),counts.end(),comp); //sort preserving the order
    vector<int> positions;
    for(int i=0;i<counts.size();i++)
    {
        positions.push_back(counts[i].second);
    }
    return positions;
}
