bool isSafe(vector<string> board,int row,int column,int n)
{
    //check all rows at this column
    for(int i=0;i<n;i++)
    {
        if(board[i][column]=='Q')
            return false;
    }
    //check all columns at this row
    for(int i=0;i<n;i++)
    {
        if(board[row][i]=='Q')
            return false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-j==row-column)
            {
                if(board[i][j]=='Q')
                    return false;
            }
            if(i+j==row+column)
            {
                if(board[i][j]=='Q')
                    return false;
            }
        }
    }
    return true;
}

void nQueen(vector<vector<string> > &result,vector<string> &board,int row,int n)
{
    if(row==n)
    {
        result.push_back(board);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(board,row,i,n)==true)
        {
            board[row][i]='Q';
            nQueen(result,board,row+1,n);
            board[row][i]='.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> board(n,string(n,'.'));//n strings on length n initialized as .....
    vector<vector<string> > result;
    nQueen(result,board,0,n);
    return result;
}
