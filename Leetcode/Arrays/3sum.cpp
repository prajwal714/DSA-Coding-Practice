
//This sol handles the duplicate elements, and return the set of 3 elements which form a sum =0
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int i,j,k;
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(k=n-1;k>=2;k--)
        {
           if(k<n-1 &&nums[k]==nums[k+1])
               continue;
            i=0;j=k-1;
            while(i<j)
            {
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==0)
                {
                    
                    res.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    
                    while(i<j && nums[i+1]==nums[i])
                        i++;
                    while(i<j &&nums[j]==nums[j-1])
                        j--;
                    
                    i++;
                    j--;

                }
                else if(sum<0)
                    i++;
                else
                    j--;
            }
        }
        
        return res;
    }
};