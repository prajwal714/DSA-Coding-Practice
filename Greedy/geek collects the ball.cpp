/* There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. 
The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them. 
Geek starts from the end of the road which has the bucket with a lower number of balls(i.e. 
if buckets are sorted in increasing order, then geek will start from the left side of the road).
The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads).
 Now you need to help Geek to collect the maximum number of balls.*/
 
 
 #include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    
	    vector<int> v1(n,0);
	    vector<int> v2(m,0);
	    int i,j;
	    for(i=0;i<n;i++)
	    cin>>v1[i];
	    
	    for(i=0;i<m;i++)
	    cin>>v2[i];
	    
	    unordered_map<int,int> m1;
	    for(i=0;i<n;i++)
	    m1[v1[i]]++;
	    
	    vector<int> common;
	    
	    for(i=0;i<m;i++)
	    {
	      if(m1[v2[i]])
	      common.push_back(v2[i]);
	        
	    }
	      
	    
	    int sum1=0;
	    int sum2=0;
	     i=0,j=0;
	     int k=0;
	     
	     int maxSum=0;
	    while(i<n&&j<m&&k<common.size())
	    {
	        auto it1=upper_bound(v1.begin(),v1.end(),common[k]);
	        
	        auto it2=upper_bound(v2.begin(),v2.end(),common[k]);
	        
	        for(;i<(it1-v1.begin());i++)
	        sum1+=v1[i];
	        
	        for(;j<(it2-v2.begin());j++)
	        sum2+=v2[j];
	        
	        //cout<<" sum1: "<<sum1<<" sum2: "<<sum2<<endl;
	        
	        maxSum+=max(sum1,sum2);
	        sum1=sum2=0;
	        
	        k++;
	        
	      
	    }
	    while(i!=n)
	    sum1+=v1[i++];
	    
	    while(j!=m)
	    sum2+=v2[j++];
	    cout<<maxSum+max(sum1,sum2)<<endl;
	}
	return 0;
}
