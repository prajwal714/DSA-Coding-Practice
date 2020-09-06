class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int res=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        
        return res;
        
    }
    
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        if(x<0 || x>=grid.size()|| y<0 || y>=grid[0].size() || grid[x][y]=='0')
            return;
        
        grid[x][y]='0';
        
        dfs(grid, x+1,y);
        dfs(grid, x,y+1);
        dfs(grid,x,y-1);
        dfs(grid, x-1,y);
    }
};