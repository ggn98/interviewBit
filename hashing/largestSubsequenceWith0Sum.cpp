vector<int> Solution::lszero(vector<int> &A) 
{
    unordered_map<int,int> myMap;
    vector<int> sumArray,result;
    int sum;
    int start=-1,end=-1,maxDiff=-1;
    //start-> start of subsequence
    //end->last element included in subsequence
    //maxDiff=size of subSequence
    sumArray.push_back(A[0]);
    for(int i=1;i<A.size();i++)
    {
        sumArray.push_back(sumArray[i-1]+A[i]); //calculate sum from 0 to i
    }
    for(int i=0;i<sumArray.size();i++)
    {
        if(sumArray[i]==0)
        {
            if(maxDiff < i+1) //i+1 is the size of subsequence when sum[i]=0
            {
                maxDiff=i+1; //upadte maxDiff
                start=0;     //start=0, as sum [0....i] is 0
                end=i;       //index of last element in subSequence i.e ith element 
            }
        }
       else
       {
           if(myMap.find(sumArray[i])!=myMap.end()) // this sum already exists
            {
                if(maxDiff < i-(myMap.find(sumArray[i])->second)) //now size of subsequence is the difference between 
                    {                                             //current position and position of element at which sum is same
                        maxDiff=i-(myMap.find(sumArray[i])->second); //update max difference
                        start=myMap.find(sumArray[i])->second+1;     //now start is one element after the element at which sum is found to be same
                        end=i;                                    //ans end is ith element as this is the last element included in our sum 
                    }
            }
            else
            {
                myMap[sumArray[i]]=i; //this sum is unique , add this to hashmap
            }
       }
    }
    if(start<0&&end<0) //means no subsequence with sum=0
    {
        return result;
    }
    for(int i=start;i<=end;i++)
    {
        result.push_back(A[i]);
    }
    return result;
}
