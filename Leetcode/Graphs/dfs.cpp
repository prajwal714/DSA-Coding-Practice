
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
   
    cin>>t;
    while(t--)
    {
         int n,e;
        cin>>n;

        vector<int> g[n];

        for(int i=0;i<e;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<bool> vis(n);
       
        dfs(0, g, vis);

    }
}

void dfs(int start, vector<int> g[], vector<bool> &vis)
{
  vis[start]=true;
  cout<<start<<" ";
  for(int i=0;i<g[start].size();i++)
  {
        if(vis[g[start][i]]=false)
            dfs(g[start][i], g, vis);
  }
}