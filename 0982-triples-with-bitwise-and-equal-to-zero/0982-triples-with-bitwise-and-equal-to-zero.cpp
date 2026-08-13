class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> arr(1 << 16, 0);
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                arr[nums[i] & nums[j]]++;
        }
        int maxi = 1 << 16;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < maxi; j++) {
                if ((j & nums[i]) == 0)
                    ans += arr[j];
            }
        }
        return ans;
    }
};