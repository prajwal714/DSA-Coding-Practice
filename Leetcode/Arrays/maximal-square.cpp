class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        int side=0;
        int i,j;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                    side=max(side, dp[i][j]);
                }
            }
        }
        
        return side*side;
        
  

    
   
    }
};
