class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        set<vector<int>> st;
        vector<int> temp;
        solve(1, n, k, temp, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

private:
    void solve(int start, int n, int k, vector<int>& temp,set<vector<int>>& st) {
        if (temp.size() == k) {
            if (!st.count(temp))
                st.insert(temp);
            return;
        }
        for (int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i + 1, n, k, temp, st);
            temp.pop_back();
        }
    }
};