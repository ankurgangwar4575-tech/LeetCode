bool dp[501][501][2];
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, sizeof(dp), false);
        return solve(0, n - 1, true, 0, 0, piles);
    }

private:
    bool solve(int i, int j, bool turn, int score1, int score2,
               vector<int>& piles) {
        if (i > j)
            return score1 > score2;
        if (dp[i][j][turn])
            return dp[i][j][turn];
        if (turn) {
            return dp[i][j][turn] =
                       solve(i + 1, j, false, score1 + piles[i], score2, piles) ||
                       solve(i, j - 1, false, score1 + piles[j], score2, piles);
        } else {
            return dp[i][j][turn] =
                       solve(i + 1, j, true, score1, score2 + piles[i], piles) &&
                       solve(i, j - 1, true, score1, score2 + piles[j], piles);
        }
    }
};