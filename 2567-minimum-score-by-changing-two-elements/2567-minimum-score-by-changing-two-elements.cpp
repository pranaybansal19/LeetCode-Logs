class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()<=3) return 0;
        int n=nums.size();

        sort(nums.begin(),nums.end());
        return min(nums[n-1]-nums[2],min(nums[n-2]-nums[1],nums[n-3]-nums[0]));
        
    }
};