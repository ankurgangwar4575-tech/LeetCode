class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int maxLen = INT_MIN;
        int i = 0;
        for (int j = 0; j < n; j++) {
            mp[nums[j]]++;
            while (i < n && mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};