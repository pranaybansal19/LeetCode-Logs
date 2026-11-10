class Solution {
public:
    // current index, prev index, vector int dp
    int helper(int i, vector<int>& dp, vector<int>& costs) {

        if (i == 0) {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        

        for (int k = 1; k <= 3; k++) {
            if (i - k >= 0) {
                int res = helper(i - k, dp, costs);
                int cst = costs[i - 1] + (k * k);
                ans = min(ans, res + cst);
            }
        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp, costs);
    }
};