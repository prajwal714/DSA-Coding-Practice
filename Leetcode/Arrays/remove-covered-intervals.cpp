
// Given a list of intervals, remove all intervals that are covered by another interval in the list.

// Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

// After doing so, return the number of remaining intervals.
class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[0]<b[0];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {
            
            
            
               
            
            if(intervals[i][0]>=res.back()[0] && intervals[i][1]<=res.back()[1] || res.back()[0]>=intervals[i][0] && res.back()[1]<=intervals[i][1])
                {
                    res.back()[0]=min(res.back()[0], intervals[i][0]);
                    res.back()[1]=max(res.back()[1], intervals[i][1]);
                
                }
            else
                 res.push_back(intervals[i]);
        }
        
        return res.size();
        
    }
};