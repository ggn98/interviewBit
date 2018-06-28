int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char,int> myMap;
    int i=0;
    int maxCount=-1,count=0;
    while(i<A.length())
    {
        if(myMap.find(A[i])==myMap.end())
        {
            myMap[A[i]]=i;
            i++;
            count++;
            if(i==A.length()&&count>maxCount)
            {
                maxCount=count;
            }
        }
        else
        {
            if(count>maxCount)
            {
                maxCount=count;
            }
            count=0;
            i=myMap.find(A[i])->second+1;
            myMap.clear();
        }
    }
    return maxCount;
}
