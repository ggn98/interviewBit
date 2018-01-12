string Solution::convertToTitle(int A) {
    string result;
    while(A>0)
    {
        int rem=A%26;
        A=A/26;
        char res=64+rem; // FINDING CORRESPONDING CHAR FOR REMAINDER
        if(rem==0)      
        {
            result+='Z';
            A--; 
        }
        else
        {
           result+=res; 
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
//IF A=26*M, THEN IN NEXT STEP IF WE DO NOT DECREMENT BY 1 ,
//IT WILL AGAIN BE A MULTIPLE OF 26 , EX=26 , 26%26=0;
//THEN IF EX=EX/26, THEN EX=1, WHILE LOOP WILL RUN AGAIN, IT WAS NOT NEEDED.
//HENCE DECREMENT 1 WHEN MULTIPLE OF 26
