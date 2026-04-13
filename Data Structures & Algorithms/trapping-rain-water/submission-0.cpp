class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0, r = height.size()-1, area = 0;
        int leftMax = height[l], rightMax = height[r];

        while (l<r){

            if (leftMax < rightMax){
                l++;
                leftMax = max(height[l], leftMax);
                area += leftMax - height[l];
            }else{
                r--;
                rightMax = max(height[r], rightMax);
                area += rightMax - height[r];
            }
        }

        return area;
        
    }
};
