class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int maxArea = 0;
        stack <pair<int, int>> stack; // index, height

        for (int i = 0; i< heights.size(); i++){ // iterating through each bar and popping
                                                 // ones that are bigger than current bar
                                                 // also calulating current max areas

            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]){ // if current height 
                                                        // is less than prev height 
                //calculating the area of the bar that we are popping incase it is the maxArea
                pair <int, int> pair = stack.top();
                maxArea = max(maxArea, pair.second * (i - pair.first));
                start = pair.first; 
                stack.pop();
            }
            stack.push({ start, heights[i]}); // pushing new bar as top
        }

        while (!stack.empty()){ // calculating remaining bars that havent been popped
                                // since they extend all the way to the end
            int index = stack.top().first;
            int height  = stack.top().second;
            maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
            stack.pop();
        }

        return maxArea;
    }
};
