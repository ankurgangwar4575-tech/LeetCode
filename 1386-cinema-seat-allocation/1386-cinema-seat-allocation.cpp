class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for (auto& seat : reservedSeats)
            mp[seat[0]].push_back(seat[1]);
        int ans = (n - mp.size()) * 2;
        for (auto& it : mp) {
            int mask = 0;
            for (auto& el : it.second)
                mask = mask | (1 << el);
            if (!(mask & (1 << 2)) && !(mask & (1 << 3)) &&
                !(mask & (1 << 4)) && !(mask & (1 << 5)) &&
                !(mask & (1 << 6)) && !(mask & (1 << 7)) &&
                !(mask & (1 << 8)) && !(mask & (1 << 9)))
                ans += 2;
            else if (!(mask & (1 << 2)) && !(mask & (1 << 3)) &&
                    !(mask & (1 << 4)) && !(mask & (1 << 5)) ||
                    !(mask & (1 << 6)) && !(mask & (1 << 7)) &&
                    !(mask & (1 << 8)) && !(mask & (1 << 9)))
                ans++;
            else if (!(mask & (1 << 4)) && !(mask & (1 << 5)) &&
                     !(mask & (1 << 6)) && !(mask & (1 << 7)) &&
                     (mask & (1 << 2) || mask & (1 << 3) || mask & (1 << 8) ||
                      mask & (1 << 9)))
                ans++;
        }
        return ans;
    }
};