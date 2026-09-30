class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        dfs(res, stack, 0, 0, n);
        return res;
    }


    void dfs(vector<string>& res, string& s, int open, int close, int n){
        
        if(open == close && open == n){
            res.push_back(s);
            return;
        }

        if(open < n){
            s += '(';
            dfs(res, s, open+1, close, n);
            s.pop_back();
        }

        if(open > close){
            s += ')';
            dfs(res, s, open, close+1, n);
            s.pop_back();
        }
    }
};
