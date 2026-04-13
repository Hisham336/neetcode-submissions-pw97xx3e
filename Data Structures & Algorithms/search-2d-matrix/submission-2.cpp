class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(), n = matrix[0].size()-1;

        int l= 0, r = m-1;

        while(l<=r){
            int mid = (l+r)/2;

            if(target < matrix[mid][0]){
                r = mid-1;
            }else if (target > matrix[mid][n]){
                l = mid + 1;
            }else{
                break;
            }
        }

        if (l>r){
            return false;
        }

        int mid =  (l+r)/2;
        l = 0, r = matrix[0].size()-1;

        while(l<=r){
            int newMid = (l+r)/2;

            if(target < matrix[mid][newMid]){
                r = newMid-1;
            }else if (target > matrix[mid][newMid]){
                l = newMid + 1;
            }else{
                return true;
            }
        }

        return false;
        
    }
};
