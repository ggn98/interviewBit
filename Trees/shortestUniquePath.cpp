string compare(string s1,string s2)
{
    int i,j;
    i=0;
    j=0;
    string res="";
    while(i<s1.length()&&j<s2.length())
    {
        if(s1[i]!=s2[j])
        {
            res+=s1[i];
            return res; //this is the min string which is required to identify S1 uniquely from s2
        }
        res+=s1[i];
        i++;
        j++;
    }
}
vector<string> Solution::prefix(vector<string> &A) {
  unordered_map<string,int> myMap; //to store the original indices of string
  for(int i=0;i<A.size();i++)
  {
      myMap[A[i]]=i; //store the index of each string so that answer of that string is pushed to the required position
  }
  sort(A.begin(),A.end());
  vector<string> result;
  for(int i=0;i<A.size();i++)
  {
      result.push_back("");
  }
  //Compare each string with it's left string and right string
  //and retun the least string required to uniquely identify this string in both the cases
  //then amongst these 2 strings the string whose length is more is the string which would act
  //as prefix and uniquely identify the goven string
  //for 1st string compare with only 1 on right and for last string compare only one at left
  //read description at GFG for more clear example
  for(int i=0;i<A.size();i++)
  {
      //While pushing the answer make sure it is at the right position
      if(i==0)
      {
          string right=compare(A[0],A[1]);
          result[myMap.find(A[i])->second ]=right;
      }
      else if(i==A.size()-1)
      {
          string left=compare(A[A.size()-1],A[A.size()-2]);
          result[myMap.find(A[i])->second]=left;
      }
      else
      {
          string left=compare(A[i],A[i-1]);
          string right=compare(A[i],A[i+1]);
          if(left.length()>right.length())
          {
              result[myMap.find(A[i])->second]=left;
          }
          else
          {
              result[myMap.find(A[i])->second]=right;
          }
      }
  }
  return result;
}
