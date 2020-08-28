class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        if(nums.size()<1 || k>nums.size())
            return -1;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);

            if(pq.size()>k)
            pq.pop();
        }

        return pq.top();

    }
};