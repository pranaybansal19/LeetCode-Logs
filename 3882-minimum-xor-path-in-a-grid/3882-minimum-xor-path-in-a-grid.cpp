class Solution {
public:
    int recursion(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,
                  int i, int j, int x) {

        if (i == 0 && j == 0) {
            return dp[0][0][x] = (x == grid[0][0]);
        }
        if (dp[i][j][x] != -1)
            return dp[i][j][x];

        int prevXor = x ^ grid[i][j];

        int up = 0, left = 0;

        if (i > 0) {
            up = recursion(grid, dp, i - 1, j, prevXor);
        }

        if (j > 0) {
            left = recursion(grid, dp, i, j - 1, prevXor);
        }

        return dp[i][j][x] = (up || left);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(1024, -1)));
        for (int x = 0; x < 1024; x++) {
            if (recursion(grid, dp, n - 1, m - 1, x)) {
                return x;
            }
        }
        return -1;
    }
};