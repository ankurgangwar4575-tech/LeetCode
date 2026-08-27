class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
     int n = nums.size();
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= i)
                temp.push_back({nums[i], i - nums[i]});
        }
        if (temp.empty())
            return 0;
        sort(temp.begin(), temp.end(), [&](auto& p1, auto& p2) {
            if (p1.first != p2.first)
                return p1.first < p2.first;
            else
                return p1.second > p2.second;
        });

        vector<int> temp2;
        int m = temp.size();
        temp2.push_back(temp[0].second);
        for (int i = 1; i < m; i++) {
            int shift = temp[i].second;
            if (shift >= temp2.back())
                temp2.push_back(shift);
            else {
                int idx = upper_bound(temp2.begin(), temp2.end(), shift) -
                          temp2.begin();
                temp2[idx] = shift;
            }
        }
        return temp2.size();
    }
};