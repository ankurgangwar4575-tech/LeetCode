using ll = long long;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<ll>> pref(n + 1, vector<ll>(30, 0));
        buildPrefixOr(pref, nums);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ll minBitwiseOr = minBitwiseOrGreaterThanK(i, n - 1, pref, k);
            ll maxBitwiseOr = maxBitwiseOrLessThanEqualK(i, n - 1, pref, k);
            int minDiff = min(abs(k - minBitwiseOr), abs(k - maxBitwiseOr));
            ans = min(ans, minDiff);
        }
        return ans;
    }

private:
    void buildPrefixOr(vector<vector<ll>>& pref, vector<int>& nums) {
        int n = nums.size();
        for (int b = 0; b < 30; b++) {
            for (int i = 0; i < n; i++) {
                pref[i + 1][b] = pref[i][b];
                if (nums[i] >> b & 1)
                    pref[i + 1][b]++;
            }
        }
    }
    ll bitwiseOr(vector<vector<ll>>& pref, int l, int r) {
        ll ans = 0;
        for (int b = 0; b < 30; b++) {
            ll oneBit = pref[r + 1][b] - pref[l][b];
            if (oneBit)
                ans |= 1LL << b;
        }
        return ans;
    }
    ll minBitwiseOrGreaterThanK(int l, int r, vector<vector<ll>>& pref, int k) {
        ll ans = INT_MAX;
        int left = l, right = r;
        while (left <= right) {
            int mid = (left + right) / 2;
            ll val = bitwiseOr(pref, l, mid);
            if (val <= k)
                left = mid + 1;
            else
                ans = min(ans, val), right = mid - 1;
        }
        return ans;
    }
    ll maxBitwiseOrLessThanEqualK(int l, int r, vector<vector<ll>>& pref, int k) {
        ll ans = INT_MIN;
        int left = l, right = r;
        while (left <= right) {
            int mid = (left + right) / 2;
            ll val = bitwiseOr(pref, l, mid);
            if (val <= k)
                ans = max(ans, val), left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }
};