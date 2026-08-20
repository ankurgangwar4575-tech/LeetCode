class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> temp = {nums[0]}, temp2 = {nums[1]};
        int n = nums.size();
        for (int i = 2; i < n; i++) {
            if (temp.back() >= temp2.back())
                temp.push_back(nums[i]);
            else
                temp2.push_back(nums[i]);
        }
        vector<int> ans;
        for (int& x : temp)
            ans.push_back(x);
        for (int& x : temp2)
            ans.push_back(x);
        return ans;
    }
};