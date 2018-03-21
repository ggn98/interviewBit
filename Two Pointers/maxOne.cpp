vector<int> Solution::maxone(vector<int> &A, int B) 
{
   int windowLeft=0,windowRight=0;
   int bestWindowLeft=0,bestWindowRight=0,bestWindow=0;
   vector<int> ans;
   int zeroesBetweenWindow=0; //no of zeroes present inside the window, excluding edges of window
   while(windowRight<A.size())
   {
       if(zeroesBetweenWindow<=B)
       {
           if(A[windowRight]==0) // as we are expanding right of window , check whether it is 0 or not
           {
               zeroesBetweenWindow++;
           }
           windowRight++;
       }
       if(zeroesBetweenWindow>B) // as we are expanding left of window , check whether it is 0 or not
       {
           if(A[windowLeft]==0)
           {
               zeroesBetweenWindow--;
           }
           windowLeft++;
       }
       if(windowRight-windowLeft>bestWindow) //update window if more elements 
       {
           bestWindow=windowRight-windowLeft;
           bestWindowLeft=windowLeft;
       }
   }
   for(int i=0;i<bestWindow;i++)
            {
                ans.push_back(bestWindowLeft+i);
            }
   return ans;
}
