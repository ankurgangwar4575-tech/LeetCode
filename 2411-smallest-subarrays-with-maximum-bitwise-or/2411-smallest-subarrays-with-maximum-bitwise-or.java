class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int n = nums.length;
        long[][] pref = new long[n + 1][30];
        for (int i = 0; i < n + 1; i++) {
            for (int b = 0; b < 30; b++)
                pref[i][b] = 0;
        }
        buildPrefixArray(pref, nums);
        int[] ans = new int[n];
        Arrays.fill(ans, 0);
        for (int i = 0; i < n; i++) {
            int left = i, right = n - 1;
            long target = bitwiseOr(pref, i, n - 1);
            int idx = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                long val = bitwiseOr(pref, i, mid);
                if (val >= target) {
                    if (val == target)
                        idx = mid;
                    right = mid - 1;
                } else
                    left = mid + 1;
            }
            ans[i] = idx - i + 1;
        }
        return ans;
    }

    private void buildPrefixArray(long[][] pref, int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int b = 0; b < 30; b++) {
                pref[i + 1][b] = pref[i][b];
                if ((nums[i] >> b & 1) == 1)
                    pref[i + 1][b]++;
            }
        }
    }

    private long bitwiseOr(long[][] pref, int l, int r) {
        long ans = 0;
        for (int b = 0; b < 30; b++) {
            long oneBit = pref[r + 1][b] - pref[l][b];
            if (oneBit > 0)
                ans |= 1 << b;
        }
        return ans;
    }
}