int dp[12][2][82][82][82];
using ll = long long;
class Solution {
public:
    Solution() { memset(dp, -1, sizeof(dp)); }

    int beautifulNumbers(int l, int r) {
        string s1 = to_string(l - 1);
        string s2 = to_string(r);

        s1 = string(10 - s1.length(), '0') + s1;
        s2 = string(10 - s2.length(), '0') + s2;

        ll ans1 = 0, ans2 = 0;

        for (int i = 1; i < 82; i++) {
            ans2 += solve(0, 1, 1, 1 % i, 0, i, s2);
            ans1 += solve(0, 1, 1, 1 % i, 0, i, s1);
        }

        return (int)(ans2 - ans1);
    }

private:
    int solve(int idx, int tight, int lz, int mod, int sum, int target,
              string& s) {
        if (idx == s.length()) {
            if (sum == target && mod == 0)
                return 1;
            return 0;
        }
        if (sum > target)
            return 0;

        if (!tight && dp[idx][lz][mod][sum][target] != -1) {
            return dp[idx][lz][mod][sum][target];
        }

        int ans = 0;
        int limit = tight == 1 ? s[idx] - '0' : 9;

        for (int i = 0; i <= limit; i++) {
            if (lz == 1 && i == 0) {
                ans += solve(idx + 1, tight && (i == limit), 1, mod, sum,
                             target, s);
            } else {
                ans += solve(idx + 1, tight && (i == limit), 0,
                             (mod * i) % target, sum + i, target, s);
            }
        }
        if (!tight) {
            dp[idx][lz][mod][sum][target] = ans;
        }
        return ans;
    }
};