class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans=INT_MIN;
        
        int m=grid.size(), n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    ans=max(ans, dfs(grid, i,j));
            }
        }
        if(ans==INT_MIN)
            return 0;
        else
        return ans;
        
        
    }
    
    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==0 || grid[x][y]==-1)
            return 0;
        
        grid[x][y]=-1;
        
        return 1+ dfs(grid,x+1,y)+dfs(grid, x, y+1)+ dfs(grid, x-1, y) + dfs(grid, x,y-1);
        
        
        
    }
};