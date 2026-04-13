class Solution {
public:
    int findMin(vector<int> &nums) {

        int l = 0, r = nums.size()-1;
        int res = nums[0];

        while(l<=r){

            if(nums[l] < nums[r]){ //entire  array is not sorted
                res = min(res, nums[l]); //if it is sorted the leftmost is smallest
                break;
            }

            int m = r + ((l-r)/2);
            res = min(res, nums[m]);

            if(nums[m] >=nums[l]){ //middle value is part of the rotated part
                l = m+1;
            }else{ // middle is part of the sorted left part
                r = m-1; // we keep going left untill we find the smalled value 
            }
        }
        return res;
    }
};
