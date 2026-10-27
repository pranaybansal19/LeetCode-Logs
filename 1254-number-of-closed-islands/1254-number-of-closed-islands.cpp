class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i,
             int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j]) {
            return;
        }
        if(grid[i][j]) return;

        vis[i][j] = 1;

        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int neigh_i = i + di[k];
            int neigh_j = j + dj[k];

            dfs(grid, vis, neigh_i, neigh_j);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            dfs(grid,vis,i,0);
            dfs(grid,vis,i,m-1);
        }
        for(int i=0;i<m;i++){
            dfs(grid,vis,0,i);
            dfs(grid,vis,n-1,i);
        }
        int ctr=0;

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    ctr++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ctr;
    }
};