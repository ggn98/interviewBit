int Solution::maxSubArray(const vector<int> &a) {
    int max_so_far=a[0];
    int curr_max=a[0];
    for(int i=1;i<a.size();i++)
    {
        curr_max=max(a[i],a[i]+curr_max);
        max_so_far=max(curr_max,max_so_far);
    }
    return max_so_far;
}