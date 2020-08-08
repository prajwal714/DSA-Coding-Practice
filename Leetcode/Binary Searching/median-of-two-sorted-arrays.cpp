class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int x=nums1.size(),y=nums2.size();
        double res;
        if(x>y)
           return findMedianSortedArrays(nums2,nums1);
        
        if(x==0)
        {
           
            if(y%2==0)
                return (double)(nums2[y/2]+nums2[(y/2)-1])/2;
            else
                return (double)nums2[y/2];
        }
        
        int low=0,high=x;
        
        while(low<=high)
        {
            int Xpartition=(low+high)/2;
            int Ypartition=(x+y+1)/2-Xpartition;
            
            int leftX=(Xpartition==0)?INT_MIN:nums1[Xpartition-1];
            int rightX=(Xpartition==x)?INT_MAX:nums1[Xpartition];
            
            int leftY=(Ypartition==0)?INT_MIN:nums2[Ypartition-1];
            int rightY=(Ypartition==y)?INT_MAX:nums2[Ypartition];
            
            if(leftX<=rightY && leftY<=rightX)
            {
                if((x+y)%2==0)
                    res=(double)(max(leftX,leftY)+min(rightX,rightY))/2;
                else
                    res=(double)max(leftX,leftY);
                
                return res;
            }
            else if(leftX>rightY)
                high=Xpartition-1;
            else if(leftY>rightX)
                low=Xpartition+1;
                
        }
        return -1;
        
        
        
    }
};