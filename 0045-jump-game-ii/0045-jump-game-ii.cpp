class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int jumps=0;
        int n=nums.size();
        if(n==1) return 0;

        while(l<n){
            int maxi=INT_MIN;

            for(int i=l;i<=r;i++){
                maxi=max(maxi,nums[i]+i);
            }
            l=r+1;
            r=maxi;
            jumps++;
            if(r>=n-1) break;
        }

        return jumps;

        
        
    }
};