class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> memo(rows, vector<int>(cols, -1));

        function<int(int, int)> dfs = [&](int r, int c) -> int {
            if (memo[r][c] != -1)
                return memo[r][c];
            int maxSteps = 0;
            vector<pair<int, int>> moves = {{-1, 1}, {0, 1}, {1, 1}};

            for (auto [dr, dc] : moves) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc < cols &&
                    grid[nr][nc] > grid[r][c]) {
                    maxSteps = max(maxSteps, 1 + dfs(nr, nc));
                }
            }

            return memo[r][c] = maxSteps;
        };

        int result = 0;
        for (int r = 0; r < rows; ++r) {
            result = max(result, dfs(r, 0));
        }

        return result;
    }
};
