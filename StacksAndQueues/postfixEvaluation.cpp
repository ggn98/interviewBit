int Solution::evalRPN(vector<string> &A) 
{
    stack<int> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=="+")
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            s.push(op1+op2);
        }
        else if(A[i]=="-")
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            s.push(op1-op2);
        }
        else if(A[i]=="*")
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            s.push(op1*op2);
        }
        else if(A[i]=="/")
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            s.push(op1/op2);
        }
        else
        {
            int num=stoi(A[i]);
            s.push(num);
        }
    }
    return s.top();
}