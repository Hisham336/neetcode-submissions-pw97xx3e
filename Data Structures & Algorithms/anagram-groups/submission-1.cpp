class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> res; // where pair.first is the key and second is the vector of anagrams

        // need to create a loop that creates the key and adds theee coresponding anagrams

        for(const auto& s : strs){
            vector <int> count(26,0); //[0,0, ..., 0] 27 zereos for each alphabet

            for(char c : s){

                count[c - 'a']++;

            }

            //converting count into a singluar string to be used as a key

            string key = to_string(count[0]); // initializing key by appending first iteration of count

            //looping through count and converting it to a string
            for (int i=1; i<26; i++){
                 key += "," + to_string(count[i]);
            }

            //adding string to its corresponding key to res map
            res[key].push_back(s);
        }

        //creating final reutrn variable
        vector<vector<string>> result;
        //isolation all anagrams without their keys and adding it to the result
        for(const auto& pair : res){ 
            result.push_back(pair.second);
        }

        return result;

        
    }
};
