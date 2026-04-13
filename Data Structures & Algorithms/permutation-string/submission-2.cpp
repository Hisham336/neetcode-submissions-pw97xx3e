class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()){
            return false;
        }

        unordered_map<char, int> charSet1;

        for (char c: s1){
            charSet1[c]++;
        }
        
        int need = charSet1.size();

        for (int i = 0; i < s2.size(); i++){
            int count = 0;
            unordered_map<char, int> charSet2;
            for (int j = i; j < s2.size(); j++){

                char c = s2[j];
                charSet2[c]++;

                if (charSet2[c] > charSet1[c]){
                    break;
                }

                if (charSet2[c] == charSet1[c]){
                    count++;
                }

               if (count == need){
                return true;
               } 
            }
        }
        return false;  
    }
};
