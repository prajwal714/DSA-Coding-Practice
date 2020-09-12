class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        
       
        
           int col=n-1;
             int row=0;
        
        while(row<m && col>=0)
        {
            if(target==matrix[row][col])
                return true;
            else if(target<matrix[row][col])
                col--;
            else
                row++;
        }
        
        return false;
    }
};