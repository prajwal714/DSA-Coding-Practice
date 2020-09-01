class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int m=matrix.size(), n=matrix[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        
        vector<vector<int>> dir={{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            
            for(auto d: dir)
            {
                int x=temp.first+d[0];
                int y=temp.second+d[1];
                
                if(x<0 || y<0 || x>=m || y>=n)
                    continue;
                
                if(dist[x][y]>dist[temp.first][temp.second]+1)
                {
                    dist[x][y]=dist[temp.first][temp.second]+1;
                    q.push({x,y});
                }
            }
        }
        
        return dist;
        
    }
};