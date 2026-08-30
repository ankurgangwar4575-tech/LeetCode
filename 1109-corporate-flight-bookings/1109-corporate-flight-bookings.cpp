class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diffArr(n + 2, 0), ans(n, 0);
        for (auto& booking : bookings) {
            diffArr[booking[0]] += booking[2];
            diffArr[booking[1] + 1] -= booking[2];
        }
        ans[0] = diffArr[1];
        for (int i = 2; i <= n; ++i) {
            ans[i - 1] = ans[i - 2] + diffArr[i];
        }
        return ans;
    }
};