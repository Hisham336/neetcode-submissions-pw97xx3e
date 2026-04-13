class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map <string, vector<string>> anagrams;
        
        for (const auto& s : strs){

            vector <int> intKey (26,0);

            for(char c : s){
                intKey[c - 'a']++; 
            }

            string key = to_string(intKey[0]);

            for (int i=1; i<26; i++){
                key += "," + to_string(intKey[i]);
            }

            anagrams[key].push_back(s);
        }

        vector<vector<string>> result;

        for (const auto& pair: anagrams){
            result.push_back(pair.second);
        }

        return result;
 
    }
};
