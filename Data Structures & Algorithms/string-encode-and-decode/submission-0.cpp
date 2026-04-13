class Solution {
public:

    string encode(vector<string>& strs) {

        string result = "";

        for (const string& str : strs){
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {

        vector<string> result;
        int i = 0;
        while (i < s.size()){
            string sSize = "";
            
            while (s[i] != '#'){
                sSize += s[i];
                i++;
                
            }

            int length = stoi(sSize);
            i++;

            result.push_back(s.substr(i, length));
            i += length;
        }

        return result;

    }
};
