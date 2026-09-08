class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

private: 

    void mergeSort(vector<int>& nums, int l, int r){
        
        if(l>=r){
            return;
        }

        int mid = (r+l)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);

        vector<int> temps;
        int i = l, j = mid + 1;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                temps.push_back(nums[i++]);
            }else{
                temps.push_back(nums[j++]);
            }
        }

        while(i <= mid){
            temps.push_back(nums[i++]);
        }

        while(j <= r){
            temps.push_back(nums[j++]);
        }

        for(int i = l; i <= r; i++){
            nums[i]= temps[i-l];
        }
    }

    
};