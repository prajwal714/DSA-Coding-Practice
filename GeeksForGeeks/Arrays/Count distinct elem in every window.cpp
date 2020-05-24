// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector <int> countDistinct(int[], int, int);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector <int> res = countDistinct(a, n, k);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/*You are required to complete below method */

// A[] : the input array
// N : size of the input array A[]
// K : size of every window

// return a vector containing the count of distinct elements
// in all the windows
vector <int> countDistinct(int arr[], int n, int k) {
    // Your code here
    unordered_map<int,int> mp;
    vector<int> res;
    int i;
    int dist=0;
    for(i=0;i<k;i++)
    {
        if(mp[arr[i]]==0)
        dist++;
        mp[arr[i]]++;
        
    }
    
    res.push_back(dist);
    
    for(;i<n;i++)
    {
        
        // cout<<dist<<" ";
        
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0)
        dist--;
        
        if(mp[arr[i]]==0)
        dist++;
        
        mp[arr[i]]++;
        
        res.push_back(dist);
    }
   return res;
}
