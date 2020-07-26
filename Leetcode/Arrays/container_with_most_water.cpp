class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        int start=0, end=n-1;
        int res=INT_MIN;
        while(start<=end){
            
            int water=min(height[start],height[end])*(end-start);
            
            res=max(res,water);
            
            if(height[start]<height[end])
                start++;
            else 
                end--;
            
        }
        
        return res;
    }
};
