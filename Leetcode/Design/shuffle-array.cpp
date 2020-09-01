class Solution {
public:
    vector<int> duplicate;
    vector<int> original;
    
    Solution(vector<int>& nums) {
        original.assign(nums.begin(), nums.end());
        duplicate.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        duplicate.assign(original.begin(), original.end());
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        for(int i=0;i<original.size();i++)
        {
            int index=(rand()%(original.size()-i))+i;
            
            swap(duplicate[i], duplicate[index]);
        }
        
        return duplicate;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */