class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
        int i;
        int n=nums.size();
        if(n==0)
            return 1;
        
        
        bool containsOne=false;
        for(i=0;i<n;i++)
        {
            if(nums[i]==1)
                containsOne=true;
            else if(nums[i]>n||nums[i]<=0)
                nums[i]=1;
        }
        
        
        if(containsOne==false)
            return 1;
        
        for(i=0;i<n;i++)
        {
            int index=abs(nums[i])-1;
            
            if(nums[index]>0)
                nums[index]=-nums[index];
        }
        
        for(i=0;i<n;i++)
        {
            if(nums[i]>=0)
                return i+1;
        }
        
        return n+1;
        
        
    }
};
