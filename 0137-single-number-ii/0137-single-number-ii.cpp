class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int b = 0; b < 32; b++) {
            int setBits = 0;
            for (int x : nums) {
                if (x >> b & 1)
                    setBits++;
            }
            if (setBits % 3 != 0)
                ans += 1 << b;
        }
        return ans;
    }
};