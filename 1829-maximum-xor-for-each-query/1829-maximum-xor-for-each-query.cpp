class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int prefXOR = nums[0];
        int maxi = (1 << maximumBit) - 1;
        for (int i = 1; i < n; i++)
            prefXOR ^= nums[i];

        for (int i = 0; i < n; i++) {
            ans[i] = maxi ^ prefXOR;
            prefXOR ^= nums[n - 1 - i];
        }
        return ans;
    }
};