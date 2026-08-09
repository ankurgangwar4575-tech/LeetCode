class Solution {
    public double minPrice(int[] prices, int[] discounts) {
        Arrays.sort(prices);
        Arrays.sort(discounts);
        int n = prices.length, m = discounts.length;
        double ans = 0;
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0) {
                double price = prices[i] * (1 - 0.01 * discounts[j]);
                ans += price;
                j--;
            } else
                ans += prices[i];
        }
        return ans;
    }
}