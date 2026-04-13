class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map <char, int> mp;
        int l = 0, r = 0;
        int maxL = 0;

        while (r < s.size()){
            
            if (mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]]+1);
            }
            mp[s[r]] = r;
            maxL = max(maxL, r-l+1);
            r++;
        }
        return maxL;
    }
};
