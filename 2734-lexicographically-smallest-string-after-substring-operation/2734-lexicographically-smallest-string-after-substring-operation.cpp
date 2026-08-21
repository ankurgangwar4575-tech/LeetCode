class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        bool changes = false;
        int idx = 0;
        while (idx < n && s[idx] == 'a')
            idx++;
        for (int i = idx; i < n; i++) {
            if (s[i] == 'a')
                break;
            s[i] = s[i] - 1;
            changes = true;
        }
        if (!changes) {
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == 'a') {
                    s[i] = 'z';
                    break;
                }
            }
        }
        return s;
    }
};