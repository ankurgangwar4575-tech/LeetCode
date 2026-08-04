class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> components(n, -1);
        components[0] = 0;

        for (int i = 1; i < n; i++) {
            components[i] = (nums[i] - nums[i - 1] <= maxDiff)
                                ? components[i - 1]
                                : components[i - 1] + 1;
        }
        int q = queries.size();
        vector<bool> ans(q, false);
        for (int i = 0; i < q; i++) {
            ans[i] = components[queries[i][0]] == components[queries[i][1]];
        }
        return ans;
    }
};