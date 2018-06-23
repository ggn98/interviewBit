vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> myMap;
    vector<int> result;
    for(int i=0;i<A.size();i++)
    {
        if(myMap.find(B-A[i])==myMap.end()) //not found
        {
            myMap.insert({A[i],i});
        }
        else
        {
            result.push_back(myMap.find(B-A[i])->second+1);
            result.push_back(i+1);
            return result;
        }
    }
    return result;
}
