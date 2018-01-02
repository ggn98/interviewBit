int distanceBw2Points(int x1,int y1,int x2,int y2)
{
    int distanceX=abs(x1-x2);
    int distanceY=abs(y1-y2);
    return max(distanceX,distanceY);
}
int Solution::coverPoints(vector<int> &x, vector<int> &y) 
{
    int ans=0;
    for(int i=0;i<x.size()-1;i++)
    {
        ans=ans+distanceBw2Points(x[i],y[i],x[i+1],y[i+1]);
    }
    return ans;
}