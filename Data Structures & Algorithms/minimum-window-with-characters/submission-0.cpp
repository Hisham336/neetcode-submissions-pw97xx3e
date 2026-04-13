class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()){ // if substring > mainstring
            return "";
        }

        unordered_map<char, int> charSet1;
        
        for (char c : t){
            charSet1[c]++;
        }

        int need = charSet1.size();
        int resL = INT_MAX;
        int startIdx = -1, l = 0;
        int have = 0;
        unordered_map<char, int> charSet2;
        for (int r = 0; r < s.size(); r++){
                char c2 = s[r];
                charSet2[c2]++;

                if (charSet1.count(c2) && charSet2[c2] == charSet1[c2]){ //if frequency of a certain char
                                                                        // is met then have is incremented
                    have++;
                }

                while (have == need) {
                    // 1. Update the result FIRST (while the window is still valid)
                    if ((r - l + 1) < resL) {
                        resL = r - l + 1;
                        startIdx = l;
                    }

                    // 2. Get the character at the left pointer
                    char leftChar = s[l];
                    
                    // 3. Remove it from our current window count
                    charSet2[leftChar]--;

                    // 4. Check if removing it broke our "have == need" condition
                    // Use leftChar here, NOT c2!
                    if (charSet1.count(leftChar) && charSet2[leftChar] < charSet1[leftChar]) {
                        have--;
                    }
                    
                    // 5. Finally, move the left pointer
                    l++;
                }
            }

        if (resL !=  INT_MAX){
            return s.substr(startIdx,resL);
        } else {
            return "";
        }
        
    
    }
};
