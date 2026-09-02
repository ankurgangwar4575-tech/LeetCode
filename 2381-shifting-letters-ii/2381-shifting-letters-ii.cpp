class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diffArr(n + 1, 0);
        for (auto& shift : shifts) {
            if (shift[2] == 1) {
                diffArr[shift[0]]++;
                diffArr[shift[1] + 1]--;
            } else {
                diffArr[shift[0]]--;
                diffArr[shift[1] + 1]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0)
                diffArr[i] = diffArr[i - 1] + diffArr[i];
            int shift = diffArr[i];
            if (shift == 0)
                continue;
            else if (shift > 0) {
                shift %= 26;
                int idx = s[i] - 'a';
                if (idx + shift < 26)
                    s[i] = shift + s[i];
                else
                    s[i] = 'a' + shift - (26 - idx);
            } else {
                shift = abs(shift) % 26;
                int idx = s[i] - 'a';
                if (shift <= idx)
                    s[i] = s[i] - shift;
                else
                    s[i] = 'z' - (shift - idx) + 1;
            }
        }
        return s;
    }
};