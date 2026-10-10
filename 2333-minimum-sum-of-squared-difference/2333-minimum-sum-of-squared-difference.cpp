
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);

        long long maxDiff = 0;
        long long ops = 1LL * k1 + k2;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        // Binary search for the minimum achievable
        // maximum difference.
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;

            for (long long d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= ops) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long target = low;
        long long used = 0;

        // Reduce every difference above target to target.
        for (long long& d : diff) {
            if (d > target) {
                used += d - target;
                d = target;
            }
        }

        // Use remaining operations to reduce target
        // values by one.
        long long remaining = ops - used;

        for (long long& d : diff) {
            if (remaining > 0 && d == target && d > 0) {
                d--;
                remaining--;
            }
        }

        long long ans = 0;

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};
