class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int len = 0, mask = 0;
            for (int j = i; j >= 0; j--) {
                if ((nums[j] & mask) != 0)
                    break;
                len++;
                mask |= nums[j];
            }
            ans = max(ans, len);
        }
        return ans;
    }
};