int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int , int > myMap;
    for(int j=0;j<A.size();j++)
    {
        if(myMap.find(B+A[j])!=myMap.end())
        {
            return 1;
        }
        else if(myMap.find(A[j]-B)!=myMap.end())
        {
            return 1;
        }
        else
        {
            myMap.insert({A[j],j});
        }
    }
    return 0;
}
