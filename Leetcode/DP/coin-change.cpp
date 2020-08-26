
//DP bottom up approach

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount<1)
            return 0;
        
        
        return helper(coins, amount);
    }
    
    int helper(vector<int> & coins, int amount)
    {
       
        vector<int> dp(amount+1, INT_MAX-1);
        
        dp[0]=0;
        
        for(int i=1;i<=amount;i++)
        {
            for(int coin: coins)
            {
                if(coin>i)
                    continue;
                
                dp[i]=min(dp[i], 1+dp[i-coin]);
            }
        }
        
        if(dp[amount]==INT_MAX-1)
            return -1;
        else
            return dp[amount];
            
    }
};










//DP top down approach
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount<1)
            return 0;
        sort(coins.begin(), coins.end());
        vector<int> count(amount, 0);
        return helper(coins, amount, count);
    }
    
    int helper(vector<int> & coins, int amount, vector<int> & count)
    {
        if(amount==0)
            return 0;
        
        if(count[amount-1]!=0)
            return count[amount-1];
        
        int min=INT_MAX;
        
        for(int coin: coins)
        {
            if(amount<coin)
                continue;
            
            int rem=helper(coins, amount-coin, count);
            
            if(rem<min && rem>=0)
                min=1+rem;
        }
        
        
        if (min==INT_MAX)
            count[amount-1]=-1;
        else
            count[amount-1]=min;
        
        return count[amount-1];
    }
};