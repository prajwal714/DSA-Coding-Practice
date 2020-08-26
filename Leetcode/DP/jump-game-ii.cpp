
//DP solution, where f[i] stores the min number of jumps req to reach last index from ith position
// O(n^2) and O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=1)
            return 0;
        
        vector<int> f(n,INT_MAX-1);
        
        f[n-1]=0;
        
        for(int i=n-2;i>=0;i--)
        {
            int maxPos=min(i+nums[i], n-1);
            for(int j=i+1;j<=maxPos;j++)
            {
                f[i]=min(f[i], 1+f[j]);
            }
        }
        
        return f[0];
    }
};

//Optimal Greedy solution, where we keep track of max Limit reachable from each i using maxJump, and update the limit whenever we reach our previous limit
// base limit is nums[0] since we will have to make intially 1 jump to reach

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=1)
            return 0;
        
        int jump=1;
        int maxReachable=nums[0], limit=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(i>limit)
            {
                jump++;
                limit=maxReachable;
            }

            maxReachable=max(maxReachable, i+nums[i]);
        }
        
        return jump;
    }
};