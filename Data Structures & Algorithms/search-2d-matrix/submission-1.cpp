class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = n-1;
        while(i < j){
            int mid = i + (j-i)/2;
            if(target >= matrix[mid][0]){
                if(target > matrix[mid][m-1]){
                    i = mid+1;
                }
                else{
                    i = mid;
                    break;
                }
            }
            else{
                j = mid-1;
            }
        }
        int ind = i; 
        i = 0, j = m-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(target == matrix[ind][mid]){
                return true;
            }
            if(target > matrix[ind][mid]){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return false;
    }
};
