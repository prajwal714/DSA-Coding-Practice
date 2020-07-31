//reverse a stack in O(1) space
#include<bits/stdc++.h>
using namespace std;

int main()
{

}

//reverses the elements in stack
void reverse(stack<int> &s)
{
    //base condition
    //when stack size is 1, it is already reverse we return it as it is
    if(s.size()==1)
    return;

    //induction step, if not we pop the top element and store it in temp;
    //call the reverse func for remaining stack and then insert our temp variable
    int temp=s.top();
    s.pop();
    reverse(s);
    insert(s, temp);

    return;
}

//inserts an element to the bottom position in stack
void insert(stack<int> &s, int key)
{
    //base condition: when stack is empty we can normally insert it
    if(s.empty())
    {
        s.push(key);
        return;
    }

    //induction step, if stack is not empty we remove one element from top, call the insert function for stack
    //then push the temp variable again

    int temp=s.top();
    s.pop();
    insert(s, key);
    s.push(temp);
    return;

}