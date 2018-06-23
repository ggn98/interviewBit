set<vector<int> > util(vector<int> &A,int index)
{
    if(index>=A.size())
    {
        vector<int> start;
        set<vector<int> > r;
        r.insert(start);
        return r;
    }
    set<vector<int> > temp=util(A,index+1);
    set<vector<int> > r;
    for(int i=0;i<temp.size();i++)
    {
        r.push_back(temp[i]);
        temp[i].push_back(A[index]);
        //sort(temp[i].begin(),temp[i].end()); , no need as sorted in decreasing at input       
        r.insert(temp[i]);
    }
    return r;
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end(),greater<int>()); //sorting given array in decreasing order , 
                                            //so that the first element can be inserted at the last of subsets received 
                                            //hence reducing need of sorting each time element is added
    set<vector<int> > r=util(A,0);
    vector<vector<int> result;
    sort(result.begin(),result.end()); //for lexographic sorting
    return r;
}
