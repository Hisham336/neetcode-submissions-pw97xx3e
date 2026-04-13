class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> charCount;
        int maxSize = 0;
        int l = 0, r = 0;

        while (r < s.size()){
            if(charCount.find(s[r]) != charCount.end()){
                l = max(l, charCount[s[r]]+1); 
            }

            charCount[s[r]] = r;
            maxSize = max(maxSize, r-l+1);
            r++;
        }

        return maxSize; 
    }
};
