class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int m=image.size(), n=image[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int color=image[sr][sc];
        image[sr][sc]=newColor;
        vector<vector<int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        visited[sr][sc]=true;
        
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            
            for(auto d: dir)
            {
                int x=temp.first+d[0];
                int y=temp.second+d[1];
                
                if(x>=0 && x<m && y>=0 && y<n && image[x][y]==color && visited[x][y]==false)
                {
                    image[x][y]=newColor;
                    q.push({x,y});
                    visited[x][y]=true;
                }
            }
        }
        
        return image;
    }
};