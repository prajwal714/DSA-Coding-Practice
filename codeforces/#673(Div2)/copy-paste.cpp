#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        int min_elem=INT_MAX;
        int min_index=-1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]<min_elem)
            {
                min_elem=arr[i];
                min_index=i;
            }

        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(i==min_index)
            continue;

            if(arr[i]>=k)
            continue;

            res+=(k-arr[i])/min_elem;

        }

        cout<<res<<endl;
        


    }
    return 0;
}