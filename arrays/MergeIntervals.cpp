/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &a, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    //handle if 1st greater than second i.e swap
    if(newInterval.start>newInterval.end)
        swap(newInterval.start,newInterval.end);
    Interval result;
    vector<Interval> ans;
    if(a.size()==0)
    {
        ans.push_back(newInterval);
        return ans;
    }
    int posStart=-1,posEnd=-1,count=0;
    for(int i=0;i<a.size();i++)
    {
        if(max(a[i].start,newInterval.start)<min(a[i].end,newInterval.end))
        {
            count++;
            if(posStart==-1)
                {posStart=i;
                posEnd=i;
                }
            else
                posEnd=i;
        }
    }
    if(count==0)
    {
        int f=0;
        if(a[0].start>newInterval.end)
        {
            ans.push_back(newInterval);
            for(int i=0;i<a.size();i++)
            ans.push_back(a[i]);
            return ans;
        }
        else if(a[a.size()-1].end<newInterval.start)
        {
            for(int i=0;i<a.size();i++)
            ans.push_back(a[i]);
            ans.push_back(newInterval);
            return ans;
        }
        else 
        {
            for(int i=0;i<a.size();i++)
            {
            if(a[i].start>newInterval.end&&f==0)
            {
               ans.push_back(newInterval);
               f=1;
            }
            ans.push_back(a[i]);
            }
        return ans;
        }
    }
    else
    {
        for(int i=0;i<posStart;i++)
        {
            ans.push_back(a[i]);
        }
        result.start=min(a[posStart].start,newInterval.start);
        result.end=max(a[posEnd].end,newInterval.end);
        ans.push_back(result);
        for(int i=posEnd+1;i<a.size();i++)
        {
            ans.push_back(a[i]);
        }
        return ans;
    }
}