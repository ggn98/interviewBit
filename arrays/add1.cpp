vector<int> Solution::plusOne(vector<int> &x) {
    int f=0;
    for(int i=0;i<x.size()&&f==0;i++)
    {
        if(x[i]!=0)
        {
            f=1;
            break;
        }
        else
        {
            x.erase(x.begin()+i);
            i--;
        }
    }
    if(x.size()==0)
    {
        x.push_back(1);
        return x;
    }
    int carry=0,add=-1;
    for(int i=x.size()-1;i>=0;i--)
    {
        if(i==x.size()-1)
            {
                add=x[i]+1;
                if(add>=10)
                {
                    add=add-10;
                    carry=1;
                }
            }
        else
        {
            add=x[i]+carry;
            if(add>=10)
                {
                    add=add-10;
                    carry=1;
                }
            else
                carry=0;
        }
        x[i]=add;
    }
    if(carry==1)
         x.insert(x.begin(),1);
    return x;
}