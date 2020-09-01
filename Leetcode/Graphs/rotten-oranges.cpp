class Solution {
public:
    
    struct orange{
    int x,y;
        
        orange(int x,int y)
        {
            this->x=x;
            this->y=y;
        }

    };
    
    bool isValid(vector<vector<int>> &matrix, int x, int y)
    {
        int m=matrix.size();
        int n=matrix[0].size();

        if(x<0 || x>=m || y<0 || y>=n)
        return false;
        else
        {
            return true;
        }

    }
    
    int orangesRotting(vector<vector<int>>&matrix) {
         queue<orange> q;

    int i,j;
    int m=matrix.size();
    int n=matrix[0].size();
        int fresh=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==2)
            {
               

                q.push(orange(i,j));
            }
            
            if(matrix[i][j]==1)
                fresh++;
        }
    }
   
        int time=0;
    while(!q.empty() && fresh>0)
    {
       
        
        int size=q.size();
        while(size--)
        {
             orange temp=q.front();
             q.pop();
        
        
            int x=temp.x, y=temp.y;
            if(isValid(matrix, x+1,y) && matrix[x+1][y]==1)
            {
                matrix[x+1][y]=2;
                q.push(orange(x+1,y));
                fresh--;
            }

            if(isValid(matrix, x-1,y) && matrix[x-1][y]==1)
            {
                matrix[x-1][y]=2;
                q.push(orange(x-1,y));
                fresh--;
            }

            if(isValid(matrix, x,y+1) && matrix[x][y+1]==1)
            {
                matrix[x][y+1]=2;
                q.push(orange(x,y+1));
                fresh--;
            }

            if(isValid(matrix, x,y-1) && matrix[x][y-1]==1)
            {
                matrix[x][y-1]=2;
                q.push(orange(x,y-1));
                fresh--;
            }

        }
        time++;
       


    }

    //in case not all oranges rot, we return -1;
    if(fresh>0)
        return -1;

    // otherwise we return the time of last orange in queue
    return time;
    }
};