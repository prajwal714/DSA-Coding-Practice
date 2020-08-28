class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
     
        
        priority_queue<pair<int,int>> pq;
        int n=points.size();
        if(n<1)
        {
            vector<vector<int>>({});
        }

        for(int i=0;i<n;i++)
        {
            int x=points[i][0],y=points[i][1];

            int distance=x*x+y*y;

            pq.push({distance, i});

            if(pq.size()>k)
            pq.pop();
        }
        vector<vector<int>> res;
        while(pq.size()!=0)
        {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
        
        
        
        
    }
    
    
};