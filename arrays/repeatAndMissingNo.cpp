#include<cmath>
vector<int> Solution::repeatedNumber(const vector<int> &x)
{
    vector<int> ans;
    int repeating=0,missing=0;
    long long sumT=0,squaresumT=0,sumO=0,squaresumO=0;
    for(int i=0;i<x.size();i++)
    {
        sumO=sumO+x[i];
    }
    sumT=(x.size()*(x.size()+1))/2;
    long long diff1=sumO-sumT;
    squaresumT=(x.size()*(x.size()+1)*((2*x.size())+1))/6;
    for(int i=0;i<x.size();i++)
    {
        squaresumO=squaresumO+(long long)pow(x[i],2);
    }
    long long diff2=squaresumO-squaresumT;
    long long add=diff2/diff1;
    repeating=(add+diff1)/2;
    missing=add-repeating;
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}