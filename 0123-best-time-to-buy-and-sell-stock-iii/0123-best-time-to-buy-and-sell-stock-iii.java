class Solution {
    public int maxProfit(int[] prices) {
         int n = prices.length;
        int[][] dp = new int[2][3];
        int[][] curr = new int[2][3];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j < 3; j++) {
                curr[1][j] = Math.max(-prices[i] + dp[0][j], dp[1][j]);
                curr[0][j] = Math.max(prices[i] + dp[1][j - 1], dp[0][j]);
            }
            dp = curr;
        }

        return dp[1][2];
    }

    private int solve(int idx, int possibleToBuy, int transactions, int[] prices, int[][][] dp) {
        if (transactions == 2 || idx == prices.length)
            return 0;
        if (dp[idx][possibleToBuy][transactions] != -1)
            return dp[idx][possibleToBuy][transactions];
        int profit = 0;
        if (possibleToBuy == 1) {
            profit = Math.max(-prices[idx] + solve(idx + 1, possibleToBuy - 1, transactions, prices, dp),
                    solve(idx + 1, possibleToBuy, transactions, prices, dp));
        } else {
            profit = Math.max(prices[idx] + solve(idx + 1, possibleToBuy + 1, transactions + 1, prices, dp),
                    solve(idx + 1, possibleToBuy, transactions, prices, dp));
        }
        return dp[idx][possibleToBuy][transactions] = profit;
    }
}