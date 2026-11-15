class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {

       
        int cnt = 0;
        // 0 1 4 9 - we want subarray of different length so basically
        // i= 0 and j= i+ len -> basically then j=1,2,3
        // i=1 and j = 2,3
        // i=2 and j = 3

        int even = 1;
        int odd = 0;
        int sum=0;

        for(int i:arr){
            sum+=i;
            if(sum%2==1){
                odd++;
                cnt=(cnt+even)%MOD;
            }else{
                even++;
                cnt=(cnt+odd)%MOD;
            }
        }
        return cnt;

    
        // Time complexity : O(N*N) - worst case complexity
    }
};