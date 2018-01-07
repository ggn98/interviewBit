vector<int> Solution::findPerm(const string A, int B) 
{
    vector<int> q,ans;
    for(int i=0;i<B;i++)
    q.push_back(i+1);
    int largest=q.size()-1;
    int smallest=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='D') //pick the largest element
        {
            ans.push_back(q[largest]);
            q[largest]=-q[largest];
            largest--;
        }
        else if (A[i]=='I')
        {
            ans.push_back(q[smallest]);
            q[smallest]=-q[smallest];
            smallest++;
        }
    }
    for(int i=0;i<q.size();i++)
    {
        if(q[i]>0)
            {
                ans.push_back(q[i]);
                break;
            }
    }
    return ans;
}