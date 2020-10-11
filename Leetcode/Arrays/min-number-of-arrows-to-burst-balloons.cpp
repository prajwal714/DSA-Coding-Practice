class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[0]<b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.size()==0)
            return 0;
        
        sort(points.begin(), points.end(), compare);
        
        vector<vector<int>> res;
        
        res.push_back(points[0]);
        
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>=res.back()[0] && points[i][0]<=res.back()[1])
            {
                res.back()[0]=max(res.back()[0], points[i][0]);
                res.back()[1]=min(res.back()[1], points[i][1]);
            }
            else
                res.push_back(points[i]);
        }
        
        return res.size();
        
    }
};