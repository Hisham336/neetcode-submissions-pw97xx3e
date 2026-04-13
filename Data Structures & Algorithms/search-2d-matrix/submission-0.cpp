class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix[0].size()-1;
        int l = 0, r = matrix.size()-1;

        while(l <=r){
            int mid = l + ((r-l)/2);

            if(matrix[mid][n] < target){
                l = mid +1;
            }else if (matrix[mid][0] > target){
                r = mid-1;
            } else{
                    break;
            }
        }


        if(l >r){
            return false;
        }

        int mid = l + ((r-l)/2);

        l = 0;
        r = n;

        while (l <=r){
            
            int newMid = l + ((r-l)/2);

            if(matrix[mid][newMid] < target){
                l = newMid +1;
            }else if (matrix[mid][newMid] > target){
                r = newMid-1;
            } else{
                    return true;
            } 

        }

            

        return false;
    }
};
