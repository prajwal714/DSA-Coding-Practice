#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct job{
    int id,dl,p;
};

bool compare(job a,job b)
{
   return a.p>b.p;
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<job> j(n);
        
        int i;
        for(i=0;i<n;i++)
        {
            cin>>j[i].id;
            cin>>j[i].dl;
            cin>>j[i].p;
        }
        sort(j.begin(),j.end(),compare);
        queue <job> q;
        int result[n];
        bool slot[n]={false};
        
        for(i=0;i<n;i++)
        {
            for(int k=min(n,j[i].dl)-1;k>=0;k--)
            {
                if(slot[k]==false)
                {
                    slot[k]=true;
                    q.push(j[i]);
                    break;
                }
            }
        }
        int profit=0;
        int count=0;
        while(!q.empty())
        {
            job temp=q.front();
            q.pop();
            profit+=temp.p;
            count++;
        }
        cout<<count<<" "<<profit<<endl;
        
        
    }
	return 0;
}
