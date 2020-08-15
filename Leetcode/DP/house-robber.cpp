class Solution {
public:
    int rob(vector<int>& nums) {
        
        //we have two choices, we can rob the current bank and the bank before the previous
        // or rob the previous bank and previous previsous banks
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n+1,0);
        
        dp[0]=0;
        dp[1]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            dp[i+1]=max(nums[i]+dp[i-1], dp[i]);
        }
        
        return dp[n];
        
        
    }
};

//time O(n), space: O(n)

//more optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        
        //we have two choices, we can rob the current bank and the bank before the previous
        // or rob the previous bank and previous previsous banks
        int n=nums.size();
        if(n==0)
            return 0;
       
        
       int prev=0;
       int prevprev=0;
         int curr;
        for(int i=0;i<n;i++)
        {
           curr=max(nums[i]+prevprev, prev);
           prevprev=prev;
           prev=curr;
        }
        
        return prev;
        
        
    }
};

//time O(n), space O(1)