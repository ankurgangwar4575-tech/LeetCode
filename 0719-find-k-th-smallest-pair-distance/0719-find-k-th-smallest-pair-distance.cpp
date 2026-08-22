class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = nums[n - 1] - nums[0];
        while (i <= j) {
            int mid = (i + j) / 2;
            int ctr = countPairs(nums, mid);
            if (ctr < k)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }

private:
    int countPairs(vector<int>& arr, int k) {
        int n = arr.size();
        int j = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && arr[j] - arr[i] <= k)
                j++;
            ans += (j - i - 1);
        }
        return ans;
    }
};