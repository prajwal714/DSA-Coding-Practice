class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        
       vector<vector<int>> dp(n, vector<int>(n, false));
        
        //every string of length 1 is palindrome
        
        int i,j;
        
        for(i=0;i<n;i++)
            dp[i][i]=true;
        
        int start=0, maxLen=1;
        

        // we check for string s of length 2
        for(i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                maxLen=2;
            }
                
            else
                dp[i][i+1]=false;
        }
        
        //for length 3 and more
        
        for(int k=3;k<=n;k++)
        {
            for(i=0;i+k-1<n;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]==true)
                {
                    dp[i][j]=true;
                    start=i;
                    maxLen=k;
                }
                    
            }
        }
        
        string res=s.substr(start, maxLen);
        
        return res;
        
        
        
        
        
    }
};