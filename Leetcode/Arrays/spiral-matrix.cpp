class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
                vector<int> res;

        int m=matrix.size(); 
        if(m==0)
            return res;
        int n=matrix[0].size();
          if(n==0)
              return res;
        
        int up=0, down=m-1, right=n-1, left=0;
        while(up<=down && left<=right)
        {
            int i;
            if(up<down)
            {
                
            }
            for(i=left;i<=right;i++)
                res.push_back(matrix[up][i]);
            up++;
            for(i=up;i<=down;i++)
                res.push_back(matrix[i][right]);
            
            right--;
            
            if( up<=down)
            {
                 for(i=right;i>=left;i--)
                res.push_back(matrix[down][i]);
            
           
            }
             down--;
            
            if(left<=right)
            {
                 for(i=down;i>=up;i--)
                res.push_back(matrix[i][left]);
            
           
            }
            left++;
            
           
                
        }
        
        return res;
    }
};