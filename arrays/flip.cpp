vector<int> Solution::flip(string A) 
{
    int count1=0;
    vector<int> arr,ans;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='1')
        {
            arr.push_back(-1);
            count1++;
        }
        else
        {
            arr.push_back(1);
        }
    }
    if(count1==A.length())
    return ans;
    int maxSoFar=arr[0],maxEndingHere=0,start=0,s=0,end=0;
    for(int i=0;i<arr.size();i++)
    {
        maxEndingHere+=arr[i];
        if(maxEndingHere>maxSoFar)
        {
            maxSoFar=maxEndingHere;
            start=s;
            end=i;
        }
        if(maxEndingHere<0)
        {
            maxEndingHere=0;
            s=i+1;
        }
    }
    ans.push_back(start+1);
    ans.push_back(end+1);
    return ans;
}