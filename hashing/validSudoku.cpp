int Solution::isValidSudoku(const vector<string> &A) 
{
    unordered_map<char,bool> myMap;
    //for row
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(A[i][j]!='.')
            {
                if(myMap.find(A[i][j])!=myMap.end())
                {
                    return 0;
                }
                else
                {
                    myMap[A[i][j]]=true;
                }
            }
        }
        
        myMap.clear();
    }
    //for column
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(A[j][i]!='.')
            {
                if(myMap.find(A[j][i])!=myMap.end())
                {
                    return 0;
                }
                else
                {
                    myMap[A[j][i]]=true;
                }
            }
        }
        myMap.clear();
    }
    //for 3X3 subMatrix
    for(int startRow=0;startRow<=6;startRow=startRow+3)
    {
        for(int startCol=0;startCol<=6;startCol=startCol+3)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                    {
                        if(A[i+startRow][j+startCol]!='.')
                        {
                            if(myMap.find(A[i+startRow][j+startCol])!=myMap.end())
                            {
                                return 0;
                            }
                            else
                            {
                                myMap[A[i+startRow][j+startCol]]=true;
                            }
                        }
                    }
            }
            myMap.clear();
        }
    }
    return 1;
}
