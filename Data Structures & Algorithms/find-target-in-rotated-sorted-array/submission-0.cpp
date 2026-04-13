class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0, r = nums.size()-1;

        while(l <=r){

            if(nums[l] < nums[r]){  //entire array is sorted or not
                break; //break if it is sorted entirely
            }

            int m = r + ((l-r)/2);

            if(nums[m] == target){
                return m;
            }

            if(nums[m] > target){// we need to find a bigger value i.e. nums[m] > target

                if(nums[m] > nums[l] && nums[l] > target){ //target not in rotated part
                    l = m+1; // go right because nums[m] > target
                } else{
                    r = m-1; // go left cause we are in the smaller sorted part
                }

            } else { // nums[m] < target

                if(nums[m] > nums[l]){ // nums[l] < nums[m] < target
                    l = m+1; // go right because nums[m] < target
                } else if (target <= nums[r]) { // nums[m] < nums[l] <= target
                    l = m+1; // go left cause we are in the smaller sorted part
                } else if(target >= nums[l]){
                    r = m-1;
                } else{
                    return -1;
                }
            }
        }

        if(l > r){
            return -1;
        }

        //regular binary search for sorted array 
        while (l<=r){

            int m = r + ((l-r)/2);

            if (nums[m] > target){
                r = m-1;
            }else if (nums[m]<target){
                l = m+1;
            }else{
                return m;
            }
        }

        return -1;
    }
};
