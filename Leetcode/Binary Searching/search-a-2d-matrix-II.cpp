class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        int i=0,j=n-1;
        
        while(i>=0 && i<=m-1 && j>=0 && j<=n-1)
        {
            int mid=matrix[i][j];
            
            if(target==mid)
                return true;
            else if(target<mid)
                j--;
            else
                i++;
        }
        return false;
        
    }
};