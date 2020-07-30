#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int k;
    s.push(1);
        s.push(2);

    s.push(3);

    s.push(4);
    k=s.size()/2+1;
    solve(s,k);


}

void solve(stack<int> &s, int k)
{
    //base condition: when k==1 we delete the top element of stacl
    if (k == 1)
    {
        s.pop();
         return;
    }

    //induction step
    //we store the top element, call the solve func for smaller stack.
    //push the temp element again on top

    int temp=s.top();
    s.pop();
    solve(s, k-1);
    s.push(temp);
    return;
}
