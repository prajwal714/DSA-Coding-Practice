class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr[0].size();
        
        int level=n/2;
        
        int i,j;
        for(i=0;i<level;i++)
        {
            for(j=i;j<n-1-i;j++)
            {
                int t=arr[i][j];
                arr[i][j]=arr[n-1-j][i];
                arr[n-1-j][i]=arr[n-1-i][n-1-j];
                arr[n-1-i][n-1-j]=arr[j][n-1-i];
                arr[j][n-1-i]=t;
            }
        }
    }
};
