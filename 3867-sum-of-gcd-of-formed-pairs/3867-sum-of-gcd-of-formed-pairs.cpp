using ll = long long;
class Solution {
public:
    ll gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxEl = 0;
        vector<int> gcd(n, 0);
        for (int i = 0; i < n; i++) {
            maxEl = max(maxEl, nums[i]);
            gcd[i] = __gcd(nums[i], maxEl);
        }
        sort(gcd.begin(), gcd.end());
        ll ans = 0;
        ll i = 0, j = n - 1;
        while (i < j) {
            ans += (__gcd(gcd[i], gcd[j]));
            i++;
            j--;
        }
        return ans;
    }
};