class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;

        for(int i=0;i<n;i++){
            int k=i+1;

            if(n%k==0){
                cout<<k<<" ";
                sum+=(nums[i]*nums[i]);
            }
        }
        return sum;
        
    }
};