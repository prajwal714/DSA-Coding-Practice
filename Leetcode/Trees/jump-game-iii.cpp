//each arr[i] has two children i+arr[i], i-arr[i], we search in this tree for array element with zero, 
//time complexity: O(n) space O(n)

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        
        
        if(start>=0 && start<arr.size() && arr[start]>=0)
        {
            if(arr[start]==0)
                return true;
        }
        else
            return false;
        
        arr[start]=-arr[start];
        
        return canReach(arr, start+arr[start]) || canReach(arr, start-arr[start]);
    }
};