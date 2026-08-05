class Solution {
    public int minCost(int n, int[] cuts) {
        Arrays.sort(cuts);
        int a = cuts.length;
        ArrayList<Integer> nums = new ArrayList<>();
        nums.add(0);
        for (int i = 0; i < a; i++)
            nums.add(cuts[i]);
        nums.add(n);
        int[][] dp = new int[a + 2][a + 2];
        for (int i = a; i > 0; i--) {
            for (int j = 1; j < a + 1; j++) {
                if (i > j)
                    continue;
                int val = Integer.MAX_VALUE;
                for (int k = i; k < j + 1; k++) {
                    int cost = nums.get(j + 1) - nums.get(i - 1) + dp[i][k - 1]
                            + dp[k + 1][j];
                    val = Math.min(val, cost);
                }
                dp[i][j] = val;
            }
        }
        return dp[1][a];
    }

    private int solve(int i, int j, ArrayList<Integer> nums, int[][] dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int val = Integer.MAX_VALUE;
        for (int k = i; k < j + 1; k++) {
            int cost = nums.get(j + 1) - nums.get(i - 1) + solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp);
            val = Math.min(val, cost);
        }
        return dp[i][j] = val;
    }
}