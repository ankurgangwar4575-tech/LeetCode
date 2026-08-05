class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int i = 0, j = n - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (nums[m] > nums[j])
                i = m + 1;
            else if (nums[m] < nums[j])
                j = m;
            else
                j--;
        }
        return nums[i];
    }
}