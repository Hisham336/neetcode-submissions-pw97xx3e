class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int, int>> stack; // index, temp
        int n = temperatures.size();
        vector<int> result(n, 0);

        for (int i = 0; i <n; i++){
            while(!stack.empty() && temperatures[i] > stack.top().second){

                result[stack.top().first] = i -stack.top().first;
                stack.pop();

            }

            stack.push({i, temperatures[i]});
        }

        return result;
        
    }
};
