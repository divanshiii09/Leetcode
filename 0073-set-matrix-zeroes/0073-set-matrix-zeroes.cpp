class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        bool rowZero = false, colZero = false;

        for (int i = 0; i < m; i++)
            if (mat[i][0] == 0) colZero = true;
        
        for (int j = 0; j < n; j++)
            if (mat[0][j] == 0) rowZero = true;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (mat[i][j] == 0) mat[i][0] = mat[0][j] = 0;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;

        if (rowZero)
            for (int j = 0; j < n; j++) mat[0][j] = 0;

        if (colZero)
            for (int i = 0; i < m; i++) mat[i][0] = 0;
    }
};
