#include<iostream>
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
        int n;
        cin>>n;
        
        vector<int> arr(n);
        vector<int> dep(n);
        vector<pair<int,int>> t;
        
        int i;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        for(i=0;i<n;i++)
        cin>>dep[i];
        
        for(i=0;i<n;i++)
        t.push_back(make_pair(arr[i],dep[i]));
        
        sort(t.begin(), t.end(), compare);
        
        int platform=1;
        vector<int> end_time;
        
        end_time.push_back(t[0].second);
        for(i=1;i<n;i++)
        {
            
            if(t[i].first==t[i].second)
            {
                // platform++;
                continue;
            }
            
            
            bool allocated=false;
            for(int j=0;j<end_time.size();j++)
            {
                if(t[i].first>end_time[j])
                {
                end_time[j]=t[i].second;
                allocated=true;          
                break;
                }
            }
            
            if(allocated==false)
            {
                end_time.push_back(t[i].second);
                platform++;
            }
            
            
        }
        
        cout<<platform<<endl;
        
    }
	//code
	return 0;
}
