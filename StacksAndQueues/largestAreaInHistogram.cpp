int Solution::largestRectangleArea(vector<int> &A) 
{
    stack<int> s;
    int i=0;
    int area,top;
    int maxArea=-1;
    while(i<A.size())
    {
        if(s.empty()==true||A[s.top()]<=A[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            top=s.top();
            s.pop();
            area=A[top]*(s.empty()? i:i-s.top()-1); //first smaller element on left=s.top(), on right=i
            if(area>maxArea)
            {
                maxArea=area;
            }
        }
    }
    while(s.empty()!=true)
    {
            top=s.top();
            s.pop();
            area=A[top]*(s.empty()? i:i-s.top()-1);
            if(area>maxArea)
            {
                maxArea=area;
            }
    }
    return maxArea;
}
