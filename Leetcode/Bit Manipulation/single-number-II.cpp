class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res=0;
        for(int i=0;i<32;i++)
        {
            int bit=0;
            for(int val:nums)
            {
                if(val&(1<<i))
                {
                    bit=(bit+1)%3;
                }
            }
            if((bit)!=0)
            {
                res+=1<<i;
            }
           
            
        }
        
        return res;
    }
};