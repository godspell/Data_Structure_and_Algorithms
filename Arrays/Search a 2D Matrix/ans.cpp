class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n = matrix.size();
       int m = matrix[0].size();
       int i = n-1, j = 0;
       while(i>=0 && j<m){
           if(matrix[i][j] == target) return true;
           else if(target < matrix[i][j])i--;
           else j++;
       }
       return false;
    }
};