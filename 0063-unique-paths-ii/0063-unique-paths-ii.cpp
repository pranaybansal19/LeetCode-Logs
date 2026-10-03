class Solution {
public:
    int path(int i,int j, vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];


        int up=0,left=0;

        if(i>0) up=path(i-1,j,obstacleGrid,dp);
        if(j>0) left=path(i,j-1,obstacleGrid,dp);

        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return path(n-1,m-1,obstacleGrid,dp);
        
    }
};