class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;

        for(int i=0;i<nums.size();i++){
            if(i>maxind) return false;
            if(maxind < nums[i]+i){
                maxind=nums[i]+i;
            }
        }
        return true;
        
    }
};