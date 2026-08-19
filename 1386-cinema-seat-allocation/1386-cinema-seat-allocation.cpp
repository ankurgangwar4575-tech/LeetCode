class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for (auto& seat : reservedSeats) {
            if (!mp.count(seat[0]))
                mp[seat[0]] = 0;
            mp[seat[0]] |= 1 << seat[1];
        }
        int ans = (n - mp.size()) * 2;
        for (auto& it : mp) {
            int mask = it.second;
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
                     (mask & (1 << 2) || mask & (1 << 3) || mask & (1 << 8) || mask & (1 << 9)))
                ans++;
        }
        return ans;
    }
};