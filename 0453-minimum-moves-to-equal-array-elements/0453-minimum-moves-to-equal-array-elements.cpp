class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sm=accumulate(nums.begin(),nums.end(),0);
        return sm - (*min_element(nums.begin(),nums.end())) * (int)nums.size();
        
    }
};