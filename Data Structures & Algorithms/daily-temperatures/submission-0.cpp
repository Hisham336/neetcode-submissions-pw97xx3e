class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair <int, int>> stack;
        vector<int> res (temperatures.size(), 0);

        for(int i =0; i< temperatures.size(); i++){
            int t = temperatures[i];
            while (!stack.empty() && stack.top().first < t){
                auto pair = stack.top();
                res[pair.second] = i - pair.second; 
                stack.pop();
            }
            stack.push({t, i});
        }
            return res;
    }
};
