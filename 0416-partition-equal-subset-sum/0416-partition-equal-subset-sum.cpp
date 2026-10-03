class Solution {
public:
// need to divide the array into two parts so how to do that , so in this we can do is take two variables storing the sum of the array 

    bool divide(int i, int sum, vector<int>&nums){
        if(sum==0)return true;
        if(i==0){
            if(sum==nums[i]) return true;
            else return false;
        }
        if(sum<0) return false;
        bool take=divide(i-1,sum-nums[i],nums);
        bool nottake=divide(i-1,sum,nums);

        return take||nottake;
            

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];


        if(sum%2==1) return false;
        else sum=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        

        for(int i=0;i<n;i++) dp[i][0]=true;
        for(int i=0;i<n;i++){
            if(nums[i]==sum) dp[0][i]=true;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool take=false;
                if(j-nums[i]>=0) take=dp[i-1][j-nums[i]];
                bool nottake=dp[i-1][j];

                dp[i][j]=take||nottake;
                
            }
        }

        return dp[n-1][sum];        
    }
};