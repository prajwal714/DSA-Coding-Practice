#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct train{
    int a,d;
    bool arr;
};

bool compare(train a,train b)
{
    return a.d<b.d;
}

int getAc(vector<train> v)
{
	
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<train> t;
	    vector<int> arv(n);
	    vector<int> dept(n);
	    int i;
	    for(i=0;i<n;i++)
	    {
			cin>>arv[i];
	        
	    }
	    
	    for(i=0;i<n;i++)
	    cin>>dept[i];
	    
	    for(i=0;i<n;i++)
	    {
	    	train temp;
	    	temp.a=arv[i];
	    	temp.d=dept[i];
	    	temp.arr=false;
	    	
	    	t.push_back(temp);
	    	cout<<"pushed"<<endl;
		}
	    sort(t.begin(),t.end(),compare);
	    vector<train> cpy=t;
	    int pt=0;
	    vector<train> temp;
	    while(temp.size()!=n)
	    {
	        pt++;
	       cout<<" loop"<<endl;
	        
	        t[0].arr=true;
	        train prv=t[0];
	        for(i=1;i<t.size();i++)
	        {
	        	
	            if(t[i].a>prv.d&&t[i].arr==false)
	            {
	            	t[i].arr=true;
	                prv=t[i];
	                
	                temp.push_back(t[i]);
	                
	                
	                
	            }
	        }
	        
	        for(int j=0;j<temp.size();j++)
	        {
	            cout<<t[j].a<<" "<<t[j].d<<endl;
	        }
	        for(auto it=t.begin();it!=t.end();it++)
	        {
	           if(t[it-t.begin()].arr==true)
	           t.erase(it);
	        }
	        
	        
	    }
	    cout<<"platform: "<<pt<<endl;
	}
	return 0;
}
