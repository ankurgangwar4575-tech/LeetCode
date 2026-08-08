class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> nums;
        vector<vector<int>> ans;
        for (auto& b : buildings) {
            nums.push_back({b[0], -b[2]});
            nums.push_back({b[1], b[2]});
        }
        sort(nums.begin(), nums.end());
        multiset<int> st;
        st.insert(0);
        int prev = 0;
        for (auto& p : nums) {
            if (p.second < 0)
                st.insert(-p.second);
            else
                st.erase(st.find(p.second));
            int maxi = *st.rbegin();
            if (maxi != prev) {
                ans.push_back({p.first, maxi});
                prev = maxi;
            }
        }
        return ans;
    }
};