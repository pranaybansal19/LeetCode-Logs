class Solution {
public:
    const int mod=1e9+7;
    int recursion(vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<int>>>& dp){
        int n=grid.size();
        int m=grid[0].size();

        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        if(grid[i][j]==1){
            if(k==0) // right
            {
                return dp[i][j][k]=recursion(grid,i,j+1,1,dp)%mod;
            }else{
                return dp[i][j][k]=recursion(grid,i+1,j,0,dp)%mod;
            }
        }

        return dp[i][j][k]=(recursion(grid,i+1,j,0,dp)%mod + recursion(grid,i,j+1,1,dp)%mod)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        return recursion(grid,0,0,2,dp);
        
    }
};