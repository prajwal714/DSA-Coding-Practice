class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int pos=-1;
        int left=0, right=arr.size()-1;
        int n=arr.size();
        
        if(x<arr[0])
            return vector<int>(arr.begin(),arr.begin()+k);
        else if(x>arr[n-1])
            return vector<int>(arr.begin()+(n-k),arr.end());
        
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            
            if(arr[mid]<=x)
            {
                pos=mid;
                left=mid+1;
                
            }
            else
                right=mid-1;
        }
        
        vector<int> res;
        
        
       
        left=pos; right=pos+1;
        while(k--)
        {
            int left_diff=INT_MAX, right_diff=INT_MAX;
            
            if(left>=0)
                left_diff=abs(x-arr[left]);
            
            if(right<arr.size())
                right_diff=abs(x-arr[right]);
            
            
            if(left_diff<=right_diff)
            {
                res.push_back(arr[left]);
                left--;
            }
            else
                res.push_back(arr[right++]);
            
           
        }
        sort(res.begin(),res.end());
        return res;
        
        
        
        
    }
};