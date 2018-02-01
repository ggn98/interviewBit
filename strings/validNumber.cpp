int Solution::isNumber(const string A) 
{
    bool noOccured=false,e=false,dot=false,space=false;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==' ')
        {
            space=true;
        }
        else if(A[i]=='e')
        {
            e=true;
            noOccured=false;
        }
        else if(A[i]=='.')
        {
            if(e==true) // as no decimel after e
            return 0;
            
            //there must be a num after .
            
            if(i==A.length()-1) 
            return 0;
            if(!(A[i+1]>='0'&&A[i+1]<='9'))
            return 0;
            
        }
        else if( ((A[i]=='+')||(A[i]=='-')) )
        {
            if(noOccured==true ) //if sign comes when a no has already occurred , return 0
                return 0;
            
            //there must be a num after + / -
            else if(i==A.length()-1)
            return 0;
            if(!(A[i+1]>='0'&&A[i+1]<='9'))
            return 0;
        }
        else if(A[i]>='0'&&A[i]<='9')
        {
            if(noOccured==false) 
                {
                    noOccured=true;
                    space=false; // as we wnt to check that whether there is a space AFTER a num has occured or not 
                }
            else
                {
                    if(space==true) // it means that num has occurred and space has also occured AFTER the last occured number
                    {
                        return 0; // hence return 0 
                    }
                    else continue;
                }
        }
        else return 0; // any char except . + - (0,9) return 0 for it
    }
    if(noOccured==true) // "       " to handle such a case
    return 1;
    else return 0;
}
