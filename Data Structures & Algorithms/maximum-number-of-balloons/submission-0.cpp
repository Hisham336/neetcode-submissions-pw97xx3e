class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> map2;
        unordered_map<char,int> map1;

        for (char c: text){
            map1[c]++;
        }

        string bal = "balloon";

        for(char c : bal){
            map2[c]++;
        }

        int res = INT_MAX;
        for(auto& entry : map2){
            res = min(res, map1[entry.first]/entry.second);
        }

        return res;
        
    }
};