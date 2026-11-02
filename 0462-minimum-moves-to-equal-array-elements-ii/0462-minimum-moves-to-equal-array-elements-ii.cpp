class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int k=-1;
        if(n%2){
            k=nums[n/2];
        }else{
            k=(nums[(n-1)/2]+nums[((n-1)/2)+1])/2;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-k);
        }
        return ans;
    }
};