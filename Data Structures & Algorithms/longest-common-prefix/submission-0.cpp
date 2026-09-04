class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];

        for(int i = 1; i< strs.size(); i++){
            int j;
            for(j = 0; j<strs[i].length(); j++){
                if( j >= prefix.length() || prefix[j]!=strs[i][j]){
                    break;
                }
            }
            prefix = prefix.substr(0,j);
        }

        return prefix;
    }
};