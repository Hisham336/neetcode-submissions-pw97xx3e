class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map; // map that has the numbers from nums list 
                                    // with their respectivre frequencues

        vector<vector<int>> frq(nums.size() + 1);
                                // vector thats contains a list of numbers grouped 
                                // by their frequency in ascending order

        for(int n : nums){
            map[n] = 1 + map[n]; // incrementing the count of n 
        }

        // filling up the frq vector
        for (const auto& part : map){
            frq[part.second].push_back(part.first);
        }

        vector <int> result;

        //filling up result with last k values of frq

        for (int i = frq.size()-1; i>0; --i){

            for (int j : frq[i]){
                result.push_back(j);
                if (result.size() == k) {
                    return result;
                }
            }
        } 

        return result;
    
    }
};
