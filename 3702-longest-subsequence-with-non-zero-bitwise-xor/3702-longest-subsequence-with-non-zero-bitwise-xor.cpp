class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool check = false;
        int n = nums.size();
        for (int b = 0; b < 32; b++) {
            int bitCount = 0;
            for (int& x : nums) {
                if (x & 1 << b)
                    bitCount++;
            }
            if (bitCount & 1)
                return n;
            else if (!(bitCount & 1) && bitCount != 0)
                check = true;
        }
        return check ? n - 1 : 0;
    }
};