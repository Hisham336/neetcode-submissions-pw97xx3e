class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map <int, int> list;
        vector<vector<int>> frq(nums.size()+1);

        for(int i : nums){  
            list[i]++;

        }

        for (const auto& part : list){
            frq[part.second].push_back(part.first);
        }


        vector<int> result;

        for(int i = frq.size()-1; i>0; i--){

            for(int j : frq[i]){
                if (k>0){
                    result.push_back(j);
                    k--;
                }
            }
        }

        return result;
        
    }
};
