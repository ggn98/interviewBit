int Solution::solve(string A) 
{
    int n=A.length();
    if(n==0||n==1)
    {
        return 0; // no additions needed
    }
    int no_Of_Characeters_In_The_Largest_Palindrome_From_Start=1;
    for(int i=0;i<n;i++)
    {
        int start=0,end=i;
        bool isPalindrome=true;
        while(start<end)
        {
            if(A[start]==A[end]) //check whether the rest of string in between is palindrome or not
            {
                start++;
                end--;
            }
            else
            {
                isPalindrome=false;
                break;
            }
        }
        if(isPalindrome==true)
        {
            no_Of_Characeters_In_The_Largest_Palindrome_From_Start=1+i; 
        }
    }
    return n-no_Of_Characeters_In_The_Largest_Palindrome_From_Start;
}
// The main idea is to find the length of largest palindrome possible in the given string , from start obviously.
// Now the total no of addition required would be length of the given string-length_of_largest_Palindrome_From_Start.