class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1, n, k, temp, ans);
        return ans;
    }

private:
    void solve(int start, int n, int k, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (temp.size() == k) {
            if (ans.empty())
                ans.push_back(temp);
            sort(temp.begin(), temp.end());
            if (!ans.empty() && ans.back() != temp)
                ans.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i + 1, n, k, temp, ans);
            temp.pop_back();
        }
    }
};