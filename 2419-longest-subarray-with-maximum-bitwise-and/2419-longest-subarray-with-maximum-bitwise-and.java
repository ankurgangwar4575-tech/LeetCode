class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int ans = 1;
        long maxBitwiseAnd = -1;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && nums[j] == nums[i])
                j++;
            if (nums[i] > maxBitwiseAnd) {
                ans = j - i;
                maxBitwiseAnd = nums[i];
            } else if (nums[i] == maxBitwiseAnd)
                ans = Math.max(ans, j - i);
            i = j - 1;
        }
        return ans;
    }
}