class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
                int n=nums.size();

        vector<int> lp(n);
        vector<int> rp(n);
        int i;
        lp[0]=1;
        rp[n-1]=1;

        int prod=1;
        for(i=1;i<n;i++)
        {
            prod*=nums[i-1];
            lp[i]=(prod);
        }
        prod=1;
        for(i=n-2;i>=0;i--)
        {
            prod*=nums[i+1];
            rp[i]=(prod);
        }
        
        vector<int> res;
        
        for(i=0;i<n;i++)
        {
            res.push_back(lp[i]*rp[i]);
        }
        
        return res;
    }
};
