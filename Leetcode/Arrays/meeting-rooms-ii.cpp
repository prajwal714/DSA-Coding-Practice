#include<bits/stdc++.h>
using namespace std;


static bool compare(vector<int> a, vector<int> b)
{
    if(a[0]==b[0])
        return a[1]<b[1];
    else
    return a[0]<b[0];
}

int minRooms(vector<vector<int>> intervals)
{
    int n=intervals.size();
    
    sort(intervals.begin(), intervals.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int count=0;
    pq.push(intervals[0][1]);
    count++;
    
    for(int i=1;i<n;i++)
    {
        if(intervals[i][0]<pq.top())
        {
            count++;
        }
        else
            pq.pop();
        
        pq.push(intervals[i][1]);
    }
    
    return count;
}

int main() {
    
    vector<vector<int>> intervals={ {0,5}, {5,10}, {15,20}};
    
    cout<<minRooms(intervals)<<endl;
    
    return 0;
}
