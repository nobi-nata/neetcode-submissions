class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size()-1;
        int l = 0;

        while(l < r){
            for(int i = 0; i < r-l; i++){
                int top = l;
                int bottom = r;

                int tl = matrix[top][l+i];
                matrix[top][l + i] = matrix[bottom - i][l];
                matrix[bottom - i][l] = matrix[bottom][r-i];
                matrix[bottom][r-i] = matrix[top + i][r];
                matrix[top+i][r] = tl;
            }
            l++;
            r--;
        }
        

    }
};
