class Solution {
public:
    int rob(vector<int>& nums) {
          int n = nums.size();
        if(n<=1)return nums[0];
        if(n==2)return max(nums[0], nums[1]); 
    int prev1 = nums[0];
    int prev2 = 0;
    int curr1 = 0;
    int negative = 0;
    for (int i = 1; i < n-1; i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0)
            pick += prev2;
        else
            pick += negative;
        int notPick = prev1;
        curr1 = max(notPick, pick);
        prev2 = prev1;
        prev1 = curr1;
    }

    int prev3 = nums[1];
    int prev4 = 0;
    int curr2 = 0;
    for (int i = 2; i < n; i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0)
            pick += prev4;
        else
            pick += negative;
        int notPick = prev3;
        curr2 = max(notPick, pick);
        prev4 = prev3;
        prev3 = curr2;
    }
    return max(curr1,curr2);
    }
};