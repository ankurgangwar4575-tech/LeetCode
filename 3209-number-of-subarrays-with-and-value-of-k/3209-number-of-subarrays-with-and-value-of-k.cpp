using ll = long long;
class Solution {
public:
    ll countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = 0;
        vector<vector<ll>> pref(n + 1, vector<ll>(32, 0));
        buildPrefixArray(pref, nums);
        for (int i = 0; i < n; i++) {
            int left = i, right = n - 1;
            int first = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (bitwiseAnd(pref, i, mid) <= k) {
                    first = mid;
                    right = mid - 1;
                } else
                    left = mid + 1;
            }
            if (first == n || bitwiseAnd(pref, i, first) != k)
                continue;
            left = i;
            right = n - 1;
            int second = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (bitwiseAnd(pref, i, mid) < k) {
                    second = mid;
                    right = mid - 1;
                } else
                    left = mid + 1;
            }
            ans += (second - first);
        }
        return ans;
    }

private:
    void buildPrefixArray(vector<vector<ll>>& pref, vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int b = 0; b < 32; b++) {
                pref[i + 1][b] = pref[i][b];
                if (!(nums[i] & 1LL << b))
                    pref[i + 1][b]++;
            }
        }
    }
    ll bitwiseAnd(vector<vector<ll>>& pref, int l, int r) {
        ll ans = 0;
        for (int b = 0; b < 32; b++) {
            ll zeroCount = pref[r + 1][b] - pref[l][b];
            if (!zeroCount)
                ans |= 1LL << b;
        }
        return ans;
    }
};
