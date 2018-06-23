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
    for (set<vector<int> >::iterator it=temp.begin(); it!=temp.end(); ++it)
    {
        vector<int> i = (*it);
        r.insert(i);
        i.push_back(A[index]);
        //sort(temp[i].begin(),temp[i].end()); , no need as sorted in decreasing at input       
        r.insert(i);
    }
    return r;
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A){
    sort(A.begin(),A.end(),greater<int>()); //sorting given array in decreasing order , 
                                            //so that the first element can be inserted at the last of subsets received 
                                            //hence reducing need of sorting each time element is added
    set<vector<int> > r=util(A,0);
    vector<vector<int> >result;
    for (set<vector<int> >::iterator it=r.begin(); it!=r.end(); ++it)
    {
        vector<int> i = (*it);
        result.push_back(i);
    }
    sort(result.begin(),result.end()); //for lexographic sorting
    return result;
}
//using set to remove duplicates
