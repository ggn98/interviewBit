vector<int> Solution::equal(vector<int> &A) {
    vector<int> result;
    unordered_map<int ,pair<int,int> > myMap;
    for(int i=0;i<A.size()-1;i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            if(myMap.find(A[i]+A[j])!=myMap.end())
            {
                if(myMap.find(A[i]+A[j])->second.first<i&&myMap.find(A[i]+A[j])->second.second!=i&&myMap.find(A[i]+A[j])->second.second!=j)
                {
                        if(result.size()==0)
                        {
                            result.push_back(myMap.find(A[i]+A[j])->second.first);
                            result.push_back(myMap.find(A[i]+A[j])->second.second);
                            result.push_back(i);
                            result.push_back(j);
                        }
                        else
                        {
                            //find that solution is lexographic or not if yes clear the old result and all new values
                            if((myMap.find(A[i]+A[j])->second.first<result[0])||(myMap.find(A[i]+A[j])->second.first==result[0]&&myMap.find(A[i]+A[j])->second.second<result[1])||(myMap.find(A[i]+A[j])->second.first==result[0]&&myMap.find(A[i]+A[j])->second.second==result[1]&&i<result[2])||(myMap.find(A[i]+A[j])->second.first==result[0]&&myMap.find(A[i]+A[j])->second.second==result[1]&&i==result[2]&&j<result[3]))
                            {
                                result.clear();
                                result.push_back(myMap.find(A[i]+A[j])->second.first);
                                result.push_back(myMap.find(A[i]+A[j])->second.second);
                                result.push_back(i);
                                result.push_back(j);
                            }
                        }
                }
            }
            else
            {
                myMap[ A[i]+A[j] ]={i,j};
            }
        }
    }
    return result;
}
