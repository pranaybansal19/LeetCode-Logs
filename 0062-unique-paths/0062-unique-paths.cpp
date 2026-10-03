class Solution {
public:
    int path(int i, int j,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        int up=0,left=0;

        if(i>0) up=path(i-1,j,dp);
        if(j>0) left=path(i,j-1,dp);

        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int j=0;j<m;j++){
            dp[j][0]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up=0,left=0;

                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];

                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
        
    }
};