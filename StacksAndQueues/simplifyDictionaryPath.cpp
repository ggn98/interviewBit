string Solution::simplifyPath(string A) 
{
    vector<string> res;
    string name="",result;
    A.push_back('/');
    //we find the string present between 2 /'s' and then do the required action
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='/') //it means a word has ended , it may be directory name or '.' or '..'
        {
            if(name.size()==0||name==".")
            {
                //do nothing
                //if we use continue here , then next loop would start , however name still contains "." , hence dont use continue
                //if using continue make sure to make name="" before continue;
            }
            else if(name=="..")
            {
                if(res.size()>0)
                    res.pop_back();
            }
            else
            {
                res.emplace_back(name); //emplace push this name to the end of vector
            }
            //since this string between /'s' have ended
            name="";
        }
        else
        {
            name=name+A[i];
        }
    }
    if(res.empty())
    return "/";
    else
    {
        for(int i=0;i<res.size();i++)
            result.append("/"+res[i]);
    }
    return result;
}