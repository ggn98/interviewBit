int Solution::threeSumClosest(vector<int> &A, int B) 
{
    sort(A.begin(),A.end());
    int ans=A[0]+A[1]+A[2] , sum;
    //ans is the sum of the triplets
    //sum is the sum of triplets at an intermediate stage
    for(int i=0;i<A.size()-2;i++)
    {
        int j=i+1;
        int k=A.size()-1;
        //for each element , see between next element and last element
        //that we can minimze the error or not
        //hence we sort , so that j++ ensures increase in sum and k-- ensures decrement in sum
        while(j<k)
        {
            sum=A[i]+A[j]+A[k];
            
            if(abs(B-sum)<abs(B-ans)) //if current sum of triplet minimizes the error , then update ans
            {
                ans=sum;
                if(ans==B) // if required sum is achieved return it
                    return ans;
            }
            
            (sum<B)?j++:k--; // inc j to increase sum of triplet , decrement k to decrease sum of triplet
        }
    }
    return ans;
    // if no sorting then we cant say that j++ would increase sum and k-- would decrease sum
    // hence we do sorting
}
