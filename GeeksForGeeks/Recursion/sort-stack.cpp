#include<bits/stdc++.h>

using namespace std;

int main()
{


}

void sort(stack<int> &s)
{
    //base condition, when single element in say it is already sorted
    if(s.size()==1)
    return;

    //induction step
    //otherwise, we pop the last element, call the sort for smaller input and insert the temp variable again
    int temp=s.top();
    s.pop();

    sort(s);

   insert(s, temp);
    return;


}

void insert(stack<int> &s, int key){
    //base condition, when s is empty of s.last element < temp
    //we simeply insert the temp and return
    if(s.size()==0||s.top()<=key)
    {
    s.push(key);
    return;

    }

    //induction step, else we store the last element, reduce the say size and call the insert function again
    // then push back the temp variable again

    int temp=s.top();
    s.pop();
    insert(s, key);
    s.push(temp);

    return;
}