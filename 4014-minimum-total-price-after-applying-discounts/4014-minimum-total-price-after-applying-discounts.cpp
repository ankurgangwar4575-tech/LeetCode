class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0;
        int n = prices.size(), m = discounts.size();
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < m) {
                double price = prices[i] * (1 - 0.01 * discounts[j]);
                ans += price;
                j++;
            } else
                ans += (double)prices[i];
        }
        return ans;
    }
};