class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> majority;
        int n = nums.size()/2;

        for(int num : nums){
            majority[num]++;

            if(majority[num] > n){
                return num;
            }
        }

    }
};