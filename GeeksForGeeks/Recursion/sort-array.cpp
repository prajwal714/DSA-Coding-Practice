#include<bits/stdc++.h>

using namespace std;

int main()
{


}

void sort(vector<int> &arr)
{
    //base condition, when single element in array it is already sorted
    if(arr.size()==1)
    return;

    //induction step
    //otherwise, we pop the last element, call the sort for smaller input and insert the temp variable again
    int temp=arr[arr.size()-1];
    arr.pop_back();

    sort(arr);

   insert(arr, temp);
    return;


}

void insert(vector<int> &arr, int key){
    //base condition, when arr is empty of arr.last element < temp
    //we simeply insert the temp and return
    if(arr.size()==0||arr[arr.size()-1]<=key)
    {
    arr.push_back(key);
    return;

    }

    //induction step, else we store the last element, reduce the array size and call the insert function again
    // then push back the temp variable again

    int temp=arr[arr.size()-1];
    arr.pop_back();
    insert(arr, key);
    arr.push_back(temp);

    return;
}