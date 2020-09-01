class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool isRow=false;
        bool isCol=false;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i,j;
        for(i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
                isRow=true;
        }
        
         for(i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
                isCol=true;
        }
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
         for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                   matrix[i][j]=0;
                }
            }
        }
        
        if(isCol)
        {
            for(i=0;i<m;i++)
                matrix[i][0]=0;
        }
        
        if(isRow)
        {
            for(i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }
        
    }
};