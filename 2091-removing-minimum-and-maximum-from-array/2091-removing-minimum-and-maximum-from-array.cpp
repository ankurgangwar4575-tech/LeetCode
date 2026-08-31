class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minEl = INT_MAX, maxEl = INT_MIN;
        int minIdx = 0, maxIdx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (minEl > nums[i]) {
                minEl = nums[i];
                minIdx = i;
            }
            if (maxEl < nums[i]) {
                maxEl = nums[i];
                maxIdx = i;
            }
        }
        if (minIdx < n / 2 && maxIdx > n / 2) {
            int ans1 = minIdx + 1 + n - maxIdx;
            int ans2 = maxIdx + 1;
            int ans3 = n - minIdx;
            return min({ans1, ans2, ans3});
        } else if (maxIdx < n / 2 && minIdx > n / 2) {
            int ans1 = maxIdx + 1 + n - minIdx;
            int ans2 = minIdx + 1;
            int ans3 = n - maxIdx;
            return min({ans1, ans2, ans3});
        } else if (minIdx >= n / 2 && maxIdx >= n / 2)
            return n - min(maxIdx, minIdx);
        return max(maxIdx, minIdx) + 1;
    }
};