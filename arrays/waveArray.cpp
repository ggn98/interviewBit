vector<int> Solution::wave(vector<int> &a) 
{
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i+=2)
    {
        swap(a[i],a[i+1]);
    }
    return a;
}