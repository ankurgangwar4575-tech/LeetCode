using ll = long long;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        ll sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += shifts[i];
            int val = sum % 26, idx = s[i] - 'a';
            if (val <= 25 - idx)
                s[i] = s[i] + val;
            else
                s[i] = 'a' + val - (26 - idx);
        }
        return s;
    }
};