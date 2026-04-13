class Solution {
public:
    int maxArea(vector<int>& heights) {

        int result = 0;
        int l = 0, r = heights.size()-1;

        while (l < r){

            int area = (r-l) * min(heights[l], heights[r]);
            result = max(result, area);

            if (heights[l] > heights[r]){
                r--;
            }else{
                l++;
            }
        }

        return result;
        
    }
};
