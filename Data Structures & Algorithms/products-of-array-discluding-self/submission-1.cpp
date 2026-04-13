class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> result (nums.size(), 1);

        //prefix pass
        for (int i = 1; i < nums.size(); i++){
                result[i] = nums[i-1]*result[i-1]; 
        }

        //postfix pass
        int postfix = 1;
        for (int i = nums.size()-1; i >= 0; i--){
                result[i] *= postfix; 
                postfix *= nums[i]; 
        }

        return result;




    }
};
