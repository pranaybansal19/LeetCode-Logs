class Solution {
public:
    int binary(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (k > nums[mid]) {
                ans = mid;
                low = mid + 1;
            } else if (k == nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (nums[ans] == k) {
            return ans - 1;
        }
        return ans;
    }
    int countPairs(vector<int>& nums, int target) {
        // nlogn - soemthing kind if binary search could be applied, so what can
        // we do after sorting , in the array we could find that how many
        // elemnts exist in the array that are smaller than the required
        // element, then increment them in the cnt

        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n=nums.size();

        for (int i = 0; i < nums.size(); i++) {
            int k = target - nums[i];

            int low = i + 1;
            int high = n - 1;
            int ans = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (nums[mid] >= k) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            cnt += ans - (i + 1);
        }
        return cnt;
    }
};