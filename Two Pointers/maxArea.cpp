int Solution::maxArea(vector<int> &A) 
{
    int left=0,right=A.size()-1;
    int area=0;
    while(left<right)
    {
        area=max(area,min(A[left],A[right])*(right-left));
        if(A[left]<A[right])
            left++;
        else
            right--;
    }
    return area;
}
//WE have area set initially as min(A[0],A[n-1]) * (n-1)
//if we want to maximise this area 
//then for sure base of that triangle will be less than this , and hence height would be surely more th
//A[0] and A[n-1]
//Hence , we increment each time the height of that side , which is less than the other