class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        
        return a[0]>b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        
        
        int n=people.size();
        
        if(n==0)
            return {};
        
        vector<vector<int>> res;
        
        sort(people.begin(), people.end(), compare);
        
        for(int i=0;i<n;i++)
        {
            
            res.insert(res.begin()+people[i][1], people[i]);
        }
        
        return res;
    }
};