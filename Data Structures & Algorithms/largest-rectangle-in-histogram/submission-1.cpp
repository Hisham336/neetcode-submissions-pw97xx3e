class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int maxArea = 0;
        stack <pair<int, int>> stack; // start, height


        for(int i = 0; i< heights.size(); i++){
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                pair <int, int> pair = stack.top();
                maxArea = max(maxArea, pair.second*(i-pair.first));
                start = pair.first;
                stack.pop();
            }
            stack.push({start, heights[i]});
        }

        while(!stack.empty()){

            pair <int, int> pair = stack.top();
            maxArea = max(maxArea, pair.second*(static_cast<int>(heights.size())-pair.first));
            stack.pop();
    
        }

        return maxArea;  
    }
};
