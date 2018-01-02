vector<vector<int> > Solution::generateMatrix(int n) 
{
  vector<vector<int> > ans(n,vector<int>(n,0));
  int left=0; //startCol
  int right=n-1; //endCol
  int top=0; //startRow
  int bottom=n-1; //endRow
  int number=1;
  int dir=0; //go right
  int i,j;
  while(left<=right&&top<=bottom)
  {
    if(dir==0)
    {
        for(i=left;i<=right;i++)
        {
            ans[top][i]=number;
            number++;
        }
        top++;
        dir=1;//go down
    }
    else if(dir==1)
    {
        for(i=top;i<=bottom;i++)
        {
            ans[i][right]=number;
            number++;
        }
        right--;
        dir=2;//go left
    }
    else if(dir==2)
    {
        for(i=right;i>=left;i--)
        {
            ans[bottom][i]=number;
            number++;
        }
        bottom--;
        dir=3;
    }
    else if(dir==3)
    {
        for(i=bottom;i>=top;i--)
        {
            ans[i][left]=number;
            number++;
        }
        left++;
        dir=0;
    }
  }
  return ans;
}