class Solution {
public:
// here the end is fixed but the starting point is not fixed can be done 
    int ways(int i, int j ,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        int m=triangle[i].size();
        if(j>=m || j<0) return INT_MAX;
        if(i==0 && j==0) return triangle[0][0];

        if(dp[i][j]!=-1) return dp[i][j];

        int up=ways(i-1,j,triangle,dp);
        int left=ways(i-1,j-1,triangle,dp);

        return dp[i][j]=min(left,up)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n=triangle.size();
        int m=triangle[n-1].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));

        for(int i=0;i<m;i++){
            int val=ways(n-1,i,triangle,dp);
            ans=min(ans,val);

        }
        return ans;
        
    }
};