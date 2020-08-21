class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        if(nums.size()<=1)
            return false;
        
        int n=nums.size();
        int sum=0;
        for(int n:nums)
        {
            sum+=n;
        }
       
        if((sum&1)!=0)
            return false;
        sum=sum/2;
        bool dp[n+1][sum+1];
        
        
        
        int i,j;
        for(i=1;i<=n;i++)
            dp[i][0]=true;
        
        for(j=1;j<=sum;j++)
            dp[0][j]=false;
        
        dp[0][0]=true;
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=sum;j++)
            {
                dp[i][j]=dp[i-1][j];
                
                if(j>=nums[i-1])
                    dp[i][j]=dp[i][j]|| dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][sum];
        
        
    }
    
   
};



//=================================backtracking solution complexity O(2^n)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int n:nums)
        {
            sum+=n;
        }
        if(sum&1!=0)
            retrurn false;
            
        return helper(nums, sum/2, 0 )
    }
    
    bool helper(vector<int> &nums, int sum, int pos)
    {
        if(sum==0)
            return true;
        
        if(pos==nums.size() || sum<0)
            return false;
        
        bool left=helper(nums, sum-nums[pos], pos+1);
        if(left==true)
            return true;
        else
            return helper(nums, sum, pos+1);
    }
};