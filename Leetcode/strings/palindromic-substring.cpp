class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.length();
       vector<vector<bool>> dp(n, vector<bool>(n,false));
        
      
        
        //for length 1 strings
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
            count++;
        }
        
        // for length 2 strings
        
        for(int i=0;i+1<n;i++)
        {
            if(s[i]==s[i+1])
            {
                count++;
                dp[i][i+1]=true;
            }
                
        }
        
        for(int k=3;k<=s.length();k++)
        {
             
            for(int i=0;i+k-1<n;i++)
            {
               
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]==true)
                {
                    count++;
                    dp[i][j]=true;
                }
                    
            }
        }
        
        return count;
            
        
    }
};