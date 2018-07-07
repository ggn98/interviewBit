int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0;
    if(A.size()==0||A.size()==1)
    return A.size();
    vector<pair<int,int> > points;
    while(i<A.size())
    {
        pair<int,int> p;
        p.first=B[i];
        p.second=A[i];
        points.push_back(p);
        i++;
    }
    //find slope of point with all the points , increment the count in map when a slope is already present
    map<pair<int,int> , int> slopeMap;
    int maxPoint = 0;
    int curMax, overlapPoints, verticalPoints;
    for(int i=0;i<points.size()-1;i++)
    {
        curMax=0;
        overlapPoints=0;
        verticalPoints=0;
        for(int j=i+1;j<points.size();j++)
        {
            if(points[j]==points[i])
            {
                overlapPoints++;
            }
            else if(points[j].first==points[i].first)
            {
                verticalPoints++;
            }
            else
            {
                int yDiff=points[j].second-points[i].second;
                int xDiff=points[j].first-points[i].first;
                int gcd=__gcd(yDiff,xDiff);
                yDiff/=gcd;
                xDiff/=gcd;
                slopeMap[make_pair(yDiff,xDiff)]++;
                curMax=max(curMax,slopeMap[{yDiff,xDiff}]);
            }
            curMax=max(curMax,verticalPoints);
        }
        maxPoint=max(maxPoint,curMax+overlapPoints+1);
        slopeMap.clear();
    }
    return maxPoint;
}
