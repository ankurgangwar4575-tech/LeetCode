class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int b = 0; b < 24; b++) {
            int ctr = 0;
            for (int x : candidates) {
                if (x & 1 << b)
                    ctr++;
            }
            ans = max(ans, ctr);
        }
        return ans;
    }
};