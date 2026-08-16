class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0; 
        int m = matrix[0].size();
        int n = matrix.size();
        int right = (m * n) - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int row = mid / m;
            int column = mid % m;
            if(matrix[row][column] == target){
                return true;
            }   
            else if(matrix[row][column] > target){
                right = mid - 1;
            }else {
                left = mid + 1 ;
            }
        }
        return false;
    }

};
