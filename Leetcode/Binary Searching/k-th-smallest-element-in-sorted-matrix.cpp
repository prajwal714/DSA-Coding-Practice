class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        if(n==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        
        while(low<high)
        {
            int mid=low+(high-low)/2;
            
            int count=0;
            
            for(int i=0;i<n;i++)
            {
                //we find the number of elements less than mid in each row, and compare it with k
                //if count<k, we increment the low value
                int pos=upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
                count+=pos;
            }
            
            if(count<k)
                low=mid+1;
            else
                high=mid;
        }
        
        return low;
        
    }
};

//complexity: O(n*log(n)* log(Range of Number of Matrix))