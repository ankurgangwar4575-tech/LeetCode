class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, -1);
        int diff = solve(0, stoneValue, dp);
        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        return "Tie";
    }

private:
    int solve(int idx, vector<int>& stoneValue, vector<int>& dp) {
        if (idx >= stoneValue.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int res = INT_MIN;
        res = max(res, stoneValue[idx] - solve(idx + 1, stoneValue, dp));
        if (idx + 1 < stoneValue.size())
            res = max(res, stoneValue[idx] + stoneValue[idx + 1] -
            solve(idx + 2, stoneValue, dp));
        if (idx + 2 < stoneValue.size())
            res = max(res, stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] - solve(idx + 3, stoneValue, dp));
        return dp[idx] = res;
    }
};