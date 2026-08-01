class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n - 1, true, 0, 0, nums);
    }

private:
    bool solve(int i, int j, bool turn, int score1, int score2,vector<int>& nums) {
        if (i == j) {
            if (turn)
                return score1 + nums[i] >= score2;
            else
                return score1 >= nums[i] + score2;
        }
        if (turn) {
            return solve(i + 1, j, false, score1 + nums[i], score2, nums) || solve(i, j - 1, false, score1 + nums[j], score2, nums);
        } else {
            return solve(i + 1, j, true, score1, score2 + nums[i], nums) && solve(i, j - 1, true, score1, score2 + nums[j], nums);
        }
    }
};