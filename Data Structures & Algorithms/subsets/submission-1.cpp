class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> sub;
        dfs(nums,sub,0);
        return res;
    }

    void dfs(vector<int>& nums,vector<int>& subSet, int idx){
       
        if(idx >= nums.size()){
            res.push_back(subSet);
            return;
        }

        subSet.push_back(nums[idx]);
        dfs(nums, subSet, idx+1);
        subSet.pop_back();
        dfs(nums, subSet, idx+1);
    }
};
