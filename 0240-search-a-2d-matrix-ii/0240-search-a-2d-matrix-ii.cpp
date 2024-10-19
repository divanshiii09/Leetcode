class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0, col = cols - 1;

        while (row < rows && col >= 0) {
            int current_element = matrix[row][col];

            if (current_element == target) {
                return true;
            } else if (current_element > target) {
                col--;
            } else {
                row++;
            }
        }

        return false;
    }
};
