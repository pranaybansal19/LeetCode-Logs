class Solution {
public:
    // so here we have to reach form last row to first row, so here we dont have
    // any styartig or ending point there are three directions in which we can
    // move ok how to start either way we can either move up

    int minpathsum(int i, int j, vector<vector<int>>& matrix,
                   vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (i == 0 && j < n && j >= 0) {
            return matrix[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = INT_MAX, right = INT_MAX;
        int up = minpathsum(i - 1, j, matrix, dp);

        if (j > 0)
            left = minpathsum(i - 1, j - 1, matrix, dp);
        if (j < m - 1)
            right = minpathsum(i - 1, j + 1, matrix, dp);

        return dp[i][j] = min(up, min(left, right)) + matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int ans = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int left=INT_MAX;
                int right=INT_MAX;

                int up=dp[i-1][j];
                if(j>0) left=dp[i-1][j-1];
                if(j<m-1) right=dp[i-1][j+1];

                dp[i][j]=min(up,min(left,right))+matrix[i][j];
            }
        }

        for(int i=0;i<m;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};