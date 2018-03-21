void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start=0,end=A.size()-1,mid=0;
    // we divide array into 4 parts
    //A[1]...A[start-1] --->contains 0
    //A[start]...A[mid-1]-->contains 1 ----->POINT 1
    //A[mid]...A[end]--->UNKNOWN ----->POINT 2
    //A[end+1]...A[N]--->@
    //Now , when we swap arr[start] and arr[mid] , when arr[mid]=0
    //we know that after swapping arr[start] would become 0 and arr[mid] would become 1
    //from point 1
    //But when arr[mid]=2 , then we swap it with arr[end]
    //but since value of arr[end] is unknown , after swapping it with mid , we dont know what mid has now , see point 2
    //hence we decrement end only , as it has 2 for sure after swap , but not increment mid as it can have anything
    while(mid<=end)
    {
        switch(A[mid])
        {
            case 0 : swap(A[start],A[mid]);
            start++;
            mid++;
            break;
            case 1 : mid++;
            break;
            case 2 : swap(A[mid],A[end]);
            end--;
            break;
        }
    }
}
