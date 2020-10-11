class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> res={0,1};
        
        if(num==0)
            return {0};
        
        if(num==1)
            return {0,1};
        
        for(int i=2;i<=num;i++)
        {
            if(i%2==0)
            {
                res.push_back(res[i/2]);
            }
            else
                res.push_back(1+res[i/2]);
        }
        
        return res;
        
        
    }
};