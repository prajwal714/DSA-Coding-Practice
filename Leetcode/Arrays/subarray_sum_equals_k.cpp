//O(n^2) solution with space complexity O(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
       int count=0;
       for(int start=0;start<n;start++)
       {
           int sum=0;
           for(int end=start;end<n;end++)
           {
               sum+=nums[end];
               if(sum==k)
                   count++;
           }
       }
        
        return count;
    }
};

//============================================================

//More optimized sol using hashmap
//we store cumulative sum, and the frq of occ of each sum. 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
       int count=0;
      
        unordered_map<int,int> mp;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            count+=mp[sum-k];
            mp[sum]++;
        }
        
        return count;
    }
};
