class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_set <char> charSet(s.begin(), s.end()); //hashmap of string s
        int res = 0;
        
        for (char c: charSet){
            int count = 0, l = 0;

            for (int r = 0; r < s.size(); r++){ //count each occurance of all chars in s
                if (s[r] == c){
                    count++;
                }
        
                while ((r-l+1) - count > k){ //reducing window size till k replacements is enough
                    if (s[l] == c){
                        count--;
                    }
                    l++;
                }
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};
