/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a,Interval b)
{
    return a.start<b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()<2)
        return A;
    sort(A.begin(),A.end(),compare);
    int first=0;
    for(int second=1;second<A.size();second++)
    {
        if(A[first].end>=A[second].start) //overlap
        {
            A[first].end=max(A[first].end,A[second].end);
        }
        else //if no overlapping , first value inreases and start and end becomes equal to the interval who is not overlapping 
        {    //as now for next entries we have to compare "first" element
            first++; //count of total intervals required till end
            A[first].start=A[second].start;
            A[first].end=A[second].end;
        }
    }
    //since the last element after merging is "first" in the vector , remove elements from first+1 to last
    A.erase(A.begin()+first+1,A.end());
    return A;
}