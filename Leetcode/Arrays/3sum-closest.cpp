class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int i,j,k;
        int n=nums.size();
        int res, minDiff=INT_MAX;
        sort(nums.begin(), nums.end());
        for(k=n-1;k>=2;k--)
        {
            i=0;j=k-1;
            while(i<j)
            {
                int sum=nums[i]+nums[j]+nums[k];
                
                if(abs(target-sum)<minDiff)
                {
                    minDiff=abs(target-sum);
                    res=sum;
                }
                
                if(target==sum)
                {
                    return sum;
                }
                else if(sum<target)
                {
                    i++;
                }
                else
                    j--;
                
            }
        }
        
        return res;
    }
};