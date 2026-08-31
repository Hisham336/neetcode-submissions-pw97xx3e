class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> charList1;
        unordered_map<char, int> charList2;

        for(int i = 0; i< s.length(); i++){
            charList1[s[i]]++;
            charList2[t[i]]++;
        }

        return charList1 == charList2;
        
    }
};
