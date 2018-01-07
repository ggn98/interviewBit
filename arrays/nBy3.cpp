int Solution::repeatedNumber(const vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(a.size()==0)
    return -1;
    if(a.size()==1)
    return a[0];
    //element1 and element2 are the 2 potential candidiates
    int element1=a[0];
    int element2=a[1];
    int count1=0,count2=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==element1) 
        {
            count1++;
        }
        else if(a[i]==element2)
        {
            count2++;
        }
        else if (count1==0) //then element1 cant be the candidate, hence upadte elememt1 and it's count
        {
            element1=a[i];
            count1=1;
        }
        else if (count2==0) //then element2 cant be the candidate, hence upadte elememt2 and it's count
        {
            element2=a[i];
            count2=1;
        }
        else //if we have 3 distinct elements at a time then we can ignore all 3, it wont affect answer .
        {
            count1--; //to ignore element1 , decremenet count1 by 1
            count2--; //to ignore element2 , decremenet count2 by 1
                      //3rd element is automatically ignored
        }
    }
    count1=0;
    count2=0;
    //now we have 2 candidates element1 and element2 , check their count 
    for(int i=0;i<a.size();i++)
    {
       if(a[i]==element1)
       {
           count1++;
       }
       else if(a[i]==element2)
       {
           count2++;
       }
    }
    if(count1>a.size()/3)
    return element1;
    else if(count2>a.size()/3)
    return element2;
    else return -1;
}
