class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int even = 0, odd = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 1)
                    odd++;
                else
                    even++;
                if (odd > 0 && odd * a >= even * b)
                    ans++;
            }
        }
        return ans;
    }
};