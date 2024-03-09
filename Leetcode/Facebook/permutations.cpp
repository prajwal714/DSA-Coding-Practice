#include<bits/stdc++.h>

/* We're using a hashmap to track which number has already been picked, 
this uses extra space complexity of O(n)
----------------------------------------------------------------
Time compexity

O(n*n!) since we loop through the nums

Space complexity
O(n)

There is another swapping based solutio with no extra space complexity  
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<bool> frq(nums.size(),false);
        vector<vector<int>> ans;
        
        generatePermutation(ans, vector<int> {}, nums, frq);
        
        return ans;
    }
    
    void generatePermutation(vector<vector<int>> &ans, vector<int> curr, vector<int> &nums, vector<bool> frq){
        
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        
        
        for(int i=0;i<nums.size();i++){
            if(!frq[i]){
                
                frq[i]=true;
                curr.push_back(nums[i]);
                generatePermutation(ans, curr, nums, frq);
                curr.pop_back();
                frq[i]=false;
            }
        }
        
    }
};

----------------------------------------------------------------

/*   
Time complexity: O(n*n!) 
Space complexity: O(n)  

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        permutateRecur(ans, nums, 0);
        return ans;
    }
    
    void permutateRecur(vector<vector<int>> &ans, vector<int> &nums, int idx){
        
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx], nums[i]);
            permutateRecur(ans, nums, idx+1);
            swap(nums[idx], nums[i]);
        }
        
    }
};