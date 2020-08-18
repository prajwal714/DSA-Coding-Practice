class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> res(digits.begin(), digits.end());
        
        reverse(res.begin(), res.end());
        
        int carry=1;
        
        for(int i=0;i<res.size();i++)
        {
            int temp=(res[i]+carry)/10;
            res[i]=(res[i]+carry)%10;
            carry=temp;
        }
        
        if(carry!=0)
            res.push_back(carry);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};