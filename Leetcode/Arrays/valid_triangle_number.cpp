class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        int res=0;
        for(int third=n-1;third>=2;third--)
        {

            int first=0,second=third-1;
            while(first<second)
            {
                if(nums[first]+nums[second]>nums[third])
                {
                    //if this condition is satisfied, all elements left of first will also be valid for traingle, total possible = second-first
                    res+=second-first;
                    second--;
                    
                }
                else
                first++;
               
            }
        }
        
        return res;
    }
};
