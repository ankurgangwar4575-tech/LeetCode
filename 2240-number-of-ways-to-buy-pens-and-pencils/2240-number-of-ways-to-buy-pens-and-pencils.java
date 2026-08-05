class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 > total && cost2 > total)
            return 1;
        long ans = 0;
        int i = 0;
        while (total - cost1 * i >= 0) {
            ans = ans + ((total - cost1 * i) / cost2 + 1);
            i++;
        }
        return ans;
    }
}