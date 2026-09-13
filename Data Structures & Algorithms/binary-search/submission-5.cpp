class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1 ;

        int m = l + ((r - l) / 2);

        while (l <= r){

            if(nums[m] == target){
                return m;
            }

            if(nums[m] > target){
                r = m-1;
            }else {
                l = m+1;
            }
            
            m = l + ((r - l) / 2);
        }

        return -1;
    }

};
