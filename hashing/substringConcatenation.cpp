vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    unordered_map<string,int> myMap;
    vector<int> ans;
    int lengthOfSubstring=0;
    for(int i=0;i<B.size();i++)
    {
        myMap[B[i]]++;
        lengthOfSubstring+=B[i].length();
    }
    if(lengthOfSubstring>A.length())
    return ans;
    for(int i=0;i<=A.length()-lengthOfSubstring;i++)
    {
        unordered_map<string,int> temp(myMap);
        string substring=A.substr(i,lengthOfSubstring);
        int k=0;
        for(int j=0;j<B.size();j++)
        {
            if(k+B[j].length()-1<substring.length())
            {
                string word=substring.substr(k,B[j].length());
                if(temp.find(word)==temp.end())
                {
                    break;
                }
                else
                {
                    temp[word]--;
                    k=k+word.length();
                }
            }
            else
            {
                break;
            }
        }
        int count=0;
        for (unordered_map<string,int>::iterator it=temp.begin(); it!=temp.end(); ++it)
            if(it->second>0)
            {
                count++;
            }
        if(count==0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
