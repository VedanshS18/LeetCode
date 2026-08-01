class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = -1;

        int start1 = 0;
        int end1 = n-1;

        while(start1 <= end1){
            int mid = start1 + (end1 - start1)/2;

            if(target >= matrix[mid][0] && target <= matrix[mid][m-1]){
                row = mid;
                break;
            }else if(target > matrix[mid][m-1]){
                start1 = mid + 1;
            }else if(target < matrix[mid][0]){
                end1 = mid - 1;
            }
        }

        if(row == -1){
            return false;
        }


        int start = 0;
        int end = m-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(target == matrix[row][mid]){
                return true;
            }else if(target > matrix[row][mid]){
                start = mid+1;
            }else if(target < matrix[row][mid]){
                end = mid-1;
            }
            
        }
        return false;
    }
};