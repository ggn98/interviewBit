stack<int> st;
stack<int> minSt;
MinStack::MinStack() {
   while(st.empty()!=true)
    st.pop();
   while(minSt.empty()!=true)
    minSt.pop();    
}
void MinStack::push(int x) { //push in both to aintain consistency
    st.push(x);
    if(minSt.empty()==true)
    {
        minSt.push(x);
    }
    else
    {
        if(x<minSt.top())
        {
            minSt.push(x);
        }
        else
        {
            minSt.push(minSt.top());
        }
    }
}
void MinStack::pop() {
    if(st.empty()==false)
    {
        st.pop();
        minSt.pop();
    }
}

int MinStack::top() {
    if(st.empty()==true)
    {
        return -1;
    }
    else
    {
        return st.top();
    }
}

int MinStack::getMin() {
    if(st.empty()==true)
    {
        return -1;
    }
    else return minSt.top();
}

