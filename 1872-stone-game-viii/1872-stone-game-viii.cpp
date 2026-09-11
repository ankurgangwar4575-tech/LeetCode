class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; ++i)
            stones[i] += stones[i - 1];
        int prevDiff = stones[n - 1], currDiff = stones[n - 1];
        for (int i = n - 2; i > 0; --i) {
            currDiff = max(prevDiff, stones[i] - prevDiff);
            prevDiff = currDiff;
        }
        return currDiff;
    }
};