//dp solution, where we build a dp table and keep track whether the current index is a good pos or not;

// time: O(n^2) space O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int dp[n];
        
        memset(dp, 0, sizeof(dp));
        
        
        int i;
       dp[n-1]=1;
       
        int good_pos=n-1;
        
        for(i=n-2;i>=0;i--)
        {
            int maxJump=i+nums[i];
            
           for(int j=i+1;j<=maxJump; j++)
           {
               if(dp[j]==1)
               {
                   dp[i]=1;
                   break;
               }
           }
        }
       
        
        return dp[0]==1;
    }
};



//greedy solution where we keep track of the closest good pos in the left, if the jump range
// is >= to this position then current position is also a good position

//time complexity: O(n), space O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int dp[n];
        
        memset(dp, 0, sizeof(dp));
        
        
        int i;
       dp[n-1]=1;
       
        int good_pos=n-1;
        
        for(i=n-2;i>=0;i--)
        {
            int maxJump=i+nums[i];
            
            if(maxJump>=good_pos)
            {
                good_pos=i;
                
            }
        }
       
        
        return good_pos==0;
    }
};