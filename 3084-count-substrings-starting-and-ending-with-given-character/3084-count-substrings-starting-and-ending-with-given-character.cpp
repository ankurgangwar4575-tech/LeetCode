using ll = long long;
class Solution {
public:
    ll countSubstrings(string s, char c) {
        ll ans = 0;
        ll ctr = 0;
        for (char& ch : s) {
            if (ch == c) {
                ans++;
                ans += ctr;
                ctr++;
            }
        }
        return ans;
    }
};