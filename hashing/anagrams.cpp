vector<vector<int> > Solution::anagrams(const vector<string> &A) {
   //sort each string and then compare if we find then they can be grouped together
   //else add in hashmap
   unordered_map<string,int> myMap;
   vector<vector<int> > result;
   for(int i=0;i<A.size();i++)
   {
       vector<int> row;
       result.push_back(row); // to avoid segmentation fault
   }
   for(int i=0;i<A.size();i++)
   {
       string temp=A[i];
       sort(temp.begin(),temp.end());
       if(myMap.find(temp)!=myMap.end()) //found
       {
           result[myMap.find(temp)->second].push_back(i+1); //add in the vector corresponding to the found index of the string
       }
       else
       {
           result[i].push_back(i+1); //as for the first time the ith string is encountered  push the index into ith vector
                                     //we return a single index if no anagram is found , hence we can add
           myMap.insert({temp,i});   //insert in hashmap
       }
   }
   int i;
   while(i<result.size()) //remove empty vectors in result
   {
       if(result[i].size()==0)
       {
           result.erase(result.begin()+i);
       }
       else
       {
           i++;
       }
   }
   return result;
}