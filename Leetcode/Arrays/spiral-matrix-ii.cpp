// fill values from 1 to n^2 in a spiral order

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n, vector<int>(n,0));
        
        int up=0,down=n-1, left=0,right=n-1;
        int k=1;
        while(up<=down && left<=right)
        {
            int i;
            for(i=left;i<=right;i++)
                matrix[up][i]=k++;
            
            up++;
            
            for(i=up;i<=down;i++)
                matrix[i][right]=k++;
            
            right--;
            
            for(i=right;i>=left;i--)
                matrix[down][i]=k++;
            
            down--;
            
            for(i=down;i>=up;i--)
                matrix[i][left]=k++;
            
            left++;
    }
        
        return matrix;
    }
};