#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first<b.first;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, target;
        cin>>n>>target;

        vector<int> a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];


        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({a[i],i});
        }
        sort(arr.begin(), arr.end(), compare);

        vector<int> res(n,0);

        int left=0, right=n-1;

        while(left<right)
        {
            int sum=arr[left].first+arr[right].first;

            if(sum==target)
            {
                res[arr[left].second]=0;
                res[arr[right].second]=1;
                left++;
                right--;
            }
            else if(sum<target)
            left++;
            else
            right--;
            
        }

        for(int i=0;i<n;i++)
        {
            cout<<res[i]<<" ";
                
        }

        cout<<endl;

    }
}