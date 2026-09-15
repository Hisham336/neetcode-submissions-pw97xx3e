class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){

        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, subset, target, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& sub, int target, int i){
        
        if(target == 0){
            res.push_back(sub);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        sub.push_back(nums[i]);
        dfs(nums, sub, target-nums[i], i+1);
        sub.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }

        dfs(nums, sub, target, i+1);
    }
};
