class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_set<char> charSet(s.begin(), s.end());
        int res = 0;
        
        for (char c: s){

            int l = 0;
            int count = 0;

            for (int r = 0; r<s.size(); r++){ //counting frequency of each char in s
                if (s[r] == c){
                    count++;
                }

                while ((r-l+1) - count > k){ // checking if number of replacements 
                                            // needed exceeds k
                    if(s[l] == c){
                        count--;
                    }
                    l++;
                }

                res = max(res, (r-l+1));
            }    
        }
        return res;
    }
};
