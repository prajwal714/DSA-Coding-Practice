class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s;
        int n=heights.size();
        int i;
        int maxArea=0;
        for(i=0;i<n;i++)
        {
            if(s.empty()||heights[s.top()]<=heights[i])
            {
                s.push(i);
            }
            else
            {
                while(!s.empty()&&heights[s.top()]>heights[i])
                {
                    int height=heights[s.top()];
                    s.pop();
                    int width=s.empty()?i:(i-s.top()-1);
                    
                     maxArea=max(maxArea, height*width);
                }
               s.push(i);
            }
        }
        
        while(!s.empty())
        {
             int height=heights[s.top()];
            s.pop();
            int width=s.empty()?i:i-s.top()-1;
                    
             maxArea=max(maxArea, height*width);
        }
        
        return maxArea;
    }
};
