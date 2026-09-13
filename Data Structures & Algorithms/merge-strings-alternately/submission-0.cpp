class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int limit = min(word1.size(), word2.size());
        int i;
        string res;
        for(i = 0; i< limit; i++){
            res +=word1[i];
            res += word2[i];
        }

        if(word1.size() > word2.size()){
            for(int j = i; j<word1.size(); j++){
                res +=word1[j];
            }
        } else {
            for(int j = i; j<word2.size(); j++){
                res +=word2[j];
            }
        }

        return res;
    }
};