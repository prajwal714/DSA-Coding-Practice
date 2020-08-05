class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int x=0;
        
        for(int val:nums)
        {
            x^=val;
        }
        //x return the first XOR second value;
        //each set bit in x either belongs to first or second, therefore we find the first set bit in x
        int first=0,second=0;
        int bit;
        for(int i=0;i<32;i++)
        {
            if(x&(1<<i))
            {
                bit=i;
                break;
                //returns the first set bit position in x
            }
        }
        
        
        for(int val:nums)
        {
            //we xor all the values whose bit position is set, this way we get first.
            if(val&(1<<bit))
            {
                first^=val;
            }
        }
        //xor of first with x gives second
        second=first^x;
        
        return vector<int> {first,second};
    }
    
};