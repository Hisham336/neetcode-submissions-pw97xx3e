class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        int i = 0;
        dfs(nums, subset, i, target);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& subset,int idx, int target){
        
        if(target == 0){
            res.push_back(subset);
            return;
        }

        if(target < 0 || idx >= nums.size()){
            return;
        }
            subset.push_back(nums[idx]);
            dfs(nums, subset, idx, target-nums[idx]);
            subset.pop_back();
            dfs(nums, subset, idx+1, target);  
    }
};
