class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       if(matrix.size()==0) return 0;

         vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(),0));
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                dp[i][j] = matrix[i][j]-'0';
                if (dp[i][j] > 0 && i>0) dp[i][j] += dp[i - 1][j];
            }
        }

        int Max = 0;
       for(int i=0;i<dp.size();i++)
       {
           Max=max(Max, largestRectangleArea(dp[i]));
       }
        

        return Max;
    }
    
    

    
    // copied "Largest Rectangle in Histogram" solution
    public:
       int largestRectangleArea(vector<int> &heights)
    {
        int maxarea=0;
        stack<int> s;
        
        for(int i=0;i<heights.size();)
        {
            if(s.empty() || heights[i]>=heights[s.top()])
                s.push(i++);
            else
            {
                int x=s.top();
                s.pop();
                int area=heights[x]*(s.empty() ? i : i-s.top()-1);
                maxarea=max(area,maxarea);
            }
        }
        
        while(!s.empty())
        {
            int x=s.top();
            s.pop();
            int area=heights[x]*(s.empty() ? heights.size() : heights.size()-s.top()-1);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }

       
    
};
