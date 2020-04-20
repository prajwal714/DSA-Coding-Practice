#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<char,int> a,pair<char,int> b)
{
    return a.second>b.second;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int k;
	    cin>>k;
	    vector<pair<char,int>> v;
	    int i;
	    
	     unordered_map<char,int> m;
	    for(i=0;i<s.length();i++)
	    {   
	        m[s[i]]++;
	    }
	    
	    

	    for(auto i=m.begin();i!=m.end();i++)
	    {
	      v.push_back(make_pair(i->first,i->second));
	    }
	    
	    sort(v.begin(),v.end(),compare);
	    long long int res=0;
	    for(i=0;i<v.size();i++)
	    {
	        cout<<v[i].first<<" ";
	        if(v[i].second>k)
	        {
	            v[i].second-=k;
	            k=0;
	        }
	        else
	        {
	            k-=v[i].second;
	            v[i].second=0;
	            
	        }
	        res+=pow(v[i].second,2);
	    }
	   cout<<res<<endl;
	    
	}
	return 0;
}
