#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct meet{
    int id;
    int start,finish;
};


bool compare(meet a,meet b)
{
    return (a.finish<b.finish);
}



int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> s(n,0);
        vector <int> f(n,0);
        
        int i;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
        }
         for(i=0;i<n;i++)
        {
            cin>>f[i];
        }
        
        vector <meet> m(n);
        
        for(i=0;i<n;i++)
        {
            
            m[i].start=s[i];
            m[i].finish=f[i];
            m[i].id=i+1;
        }
        
        sort(m.begin(),m.end(),compare);
        cout<<m[0].id<<" ";
        meet prev=m[0];
        
        // for(i=1;i<n;i++)
        // {
        //     cout<<m[i].id<<endl;
        // }
        for(i=1;i<n;i++)
        {
            meet curr=m[i];
            if(curr.start>=prev.finish)
            {
                cout<<curr.id<<" ";
                prev=curr;
            }
            
            
        }
        
        cout<<endl;
        
    }
	return 0;
}
