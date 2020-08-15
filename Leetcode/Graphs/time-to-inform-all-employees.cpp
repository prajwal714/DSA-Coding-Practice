class Solution {
public:
   
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        if(n==0)
            return 0;
        
        vector<vector<int>> graph(n);
        int i;
        
        for(i=0;i<n;i++)
        {
            if(i==headID)
                continue;
            
            graph[manager[i]].push_back(i);
        }
        
        return dfs(headID, informTime, graph);
        
        
        
        
        
    }
    
    
    int dfs(int manager, vector<int> &informTime, vector<vector<int>> &graph)
    {
     
        int time=0;
        
        for(int child: graph[manager])
        {
            time=max(time, dfs(child, informTime, graph));
        }
        
        return time+informTime[manager];
    }
   
};