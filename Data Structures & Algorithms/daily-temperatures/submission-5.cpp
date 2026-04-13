class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        stack <pair<int, int>> stack; //index info
        vector<int> result(n, 0);

        for(int i = 0; i<n ;  i++){

            while (!stack.empty() && temperatures[i] > stack.top().second){
            result[stack.top().first] = i - stack.top().first;
            stack.pop();
            } 

            stack.push({i, temperatures[i]});
        }
        
        return result;
    }


};
