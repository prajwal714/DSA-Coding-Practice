class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        if(n<1)
        return -1;


        int firstMax=NULL, secondMax=NULL, thirdMax=NULL;

        for(int i=0;i<n;i++)
        {
            if(firstMax==nums[i] || secondMax==nums[i] || thirdMax==nums[i])
            continue;

            if(firstMax==NULL || nums[i]>firstMax)
            {
                thirdMax=secondMax;
                secondMax=firstMax;
                firstMax=nums[i];
            }

            else if(secondMax==NULL || nums[i]>secondMax)
            {
                thirdMax=secondMax;
                secondMax=nums[i];
            }

            else if(thirdMax==NULL || nums[i]> thirdMax)
            thirdMax=nums[i];
        }

        if(thirdMax==NULL)
        return firstMax;
        else
        {
            return thirdMax;
        }
        
        
    }
};