class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded = "";

        for(const string& str : strs ){
            encoded += to_string(str.size()) + "#" + str;
        }

        return encoded;

    }

    vector<string> decode(string s) {

        vector<string> decoded;
        string sSize = "";

        for (int i = 0; i< s.size(); i++){
            
            if (s[i] != '#'){
                sSize += s[i];
            }else{
                int size = stoi(sSize);
                decoded.push_back(s.substr(i+1, size));
                i += size;
                sSize = "";
            }
        }

        return decoded;

    }
};
