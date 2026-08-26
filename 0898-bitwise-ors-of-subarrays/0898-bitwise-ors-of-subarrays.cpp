class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<unordered_set<int>> bitwiseOrVal(n);
        bitwiseOrVal[0].insert(nums[0]);
        st.insert(nums[0]);
        for (int i = 1; i < n; i++) {
            bitwiseOrVal[i].insert(nums[i]);
            st.insert(nums[i]);
            for (int val : bitwiseOrVal[i - 1]) {
                bitwiseOrVal[i].insert(val | nums[i]);
                st.insert(nums[i] | val);
            }
        }
        return st.size();
    }
};