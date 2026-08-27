class Solution {
public:

    int rob(vector<int>& nums) {
         vector<int> dp(nums.size(), -1);
    int n = nums.size();
    dp[0] = nums[0];
    int negative = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0)
            pick += dp[i - 2];
        else
            pick += negative;
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1]; 
    }
};