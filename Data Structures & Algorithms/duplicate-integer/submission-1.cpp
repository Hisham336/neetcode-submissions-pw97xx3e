class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> numList;

        for(int num : nums){
            if(numList.count(num)){
                return true;
            }else{
                numList.insert(num);
            }
        }

        return false;
        
    }
};