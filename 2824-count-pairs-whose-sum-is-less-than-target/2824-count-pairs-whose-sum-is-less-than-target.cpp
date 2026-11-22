class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
   
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            int k=target-nums[i];
            for(int j=0;j<i;j++){
                if(nums[j]<k) cnt++;
            }
        }
        return cnt;
        
    }
};