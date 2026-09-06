class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        vector<int> dp(n2 + 1, 0);
        dp[0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i < n1 + 1; i++) {
            vector<int> curr(n2 + 1, 0);
            curr[0] = 1;
            for (int j = 1; j < n2 + 1; j++) {
                int pick = 0;
                if (s[i - 1] == t[j - 1])
                    pick = dp[j - 1];
                int notPick = dp[j];
                curr[j] = (pick + notPick) % mod;
            }
            dp = curr;
        }
        return dp[n2];
    }
};