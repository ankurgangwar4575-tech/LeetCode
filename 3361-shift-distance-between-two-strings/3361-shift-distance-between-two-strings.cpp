class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;
        vector<long long> previous(26), next(26);
        previous[25] = previousCost[25], next[0] = nextCost[0];
        for (int i = 1; i < 26; i++)
            next[i] = next[i - 1] + nextCost[i - 1];
        for (int i = 24; i >= 0; i--)
            previous[i] = previous[i + 1] + previousCost[i + 1];
        int n = s.length();
        for (int i = 0; i < n; i++) {
            long long forwardCost = 0, backwardCost = 0;
            if (s[i] == t[i])
                continue;
            else if (s[i] < t[i]) {
                forwardCost = next[t[i] - 'a'] - next[s[i] - 'a'];
                
                backwardCost = previous[0] - previous[s[i] - 'a'] + previousCost[0] + previous[t[i] - 'a'] - previous[25];
            } else {
                forwardCost = next[25] - next[s[i] - 'a'] + nextCost[25] + next[t[i] - 'a'] - next[0];

                backwardCost = previous[t[i] - 'a'] - previous[s[i] - 'a'];
            }
            ans += min(forwardCost, backwardCost);
        }
        return ans;
    }
};