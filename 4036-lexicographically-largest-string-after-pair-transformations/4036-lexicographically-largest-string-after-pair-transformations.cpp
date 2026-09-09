class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = solve(nums[i]);
        return ans;
    }

private:
    string solve(int x) {
        string ans = "";
        char a = 'a';
        while (x > 0) {
            if (a == 'z') {
                string str(x, 'z');
                ans = str + ans;
                break;
            }
            if (x & 1)
                ans = a + ans;
            if (a < 'z')
                a++;
            x >>= 1;
        }
        return ans;
    }
};