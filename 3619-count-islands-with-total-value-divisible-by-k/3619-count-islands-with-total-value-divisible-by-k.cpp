class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j,
             long long& sum) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        if (grid[i][j] == 0 || vis[i][j])
            return;

        vis[i][j] = true;
        sum += grid[i][j];

        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int new_i = i + di[k];
            int new_j = j + dj[k];

            dfs(grid, vis, new_i, new_j, sum);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        // int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long sum = 0;
                if (!vis[i][j] && grid[i][j] != 0) {
                    dfs(grid, vis, i, j, sum);
                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};