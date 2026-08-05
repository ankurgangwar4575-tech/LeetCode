class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int maxLis = 1;
        ArrayList<Integer> dp = new ArrayList<>(Arrays.asList(nums[0]));
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp.get(dp.size() - 1)) {
                maxLis++;
                dp.add(nums[i]);
            } else {
                int idx = lowerBound(dp, nums[i]);
                dp.set(idx, nums[i]);
            }
        }
        return maxLis;
    }

    private int lowerBound(ArrayList<Integer> nums, int target) {
        int i = 0, j = nums.size() - 1;
        int idx = -1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums.get(m) >= target) {
                idx = m;
                j = m - 1;
            } else
                i = m + 1;
        }
        return idx;
    }
}