vector<int> Solution::getRow(int A) 
{
    vector<int> ans,util;
    vector<int> *ansP=&ans,*utilP=&util;
    ans.push_back(1);
    if(A==0) // if k==0 1
    return ans;
    ans.push_back(1); // if k==1 1 1
    if(A==1)
    {
        return ans;
    }
    for(int i=2;i<=A;i++) //start for k=2
    {
        utilP->push_back(1); //1st position
        for(int j=1;j<i;j++) //in the vector we need to have i+1 elements hence run this loop from 1 to i i.e i-2 times 
        {                    //as 2 values are inserted manually (1st and last)
            
            int res1=(*ansP)[j-1]; //dereferencing to use previous ans to make cuurent ans util
            int res2=(*ansP)[j];
            utilP->push_back(res1+res2);
        }
        utilP->push_back(1); //last position 
        swap(ansP,utilP); //swap the pointers of oldAns(ansP) and currentAns(util)
        utilP->erase(utilP->begin(),utilP->end()); //after Swapping , delete the elements in util as util is used to make ans ,
                                                    // however original answer is pointed by ansP after swapping
    }
    return (*ansP); //dereferencing pointer pointing ans
}