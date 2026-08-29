class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int len = n;
        string ans = s;
        bool change = false;
        int i = 0, ones = 0;
        for (int j = 0; j < n; j++) {
            ones = s[j] == '1' ? ones + 1 : ones;
            while (i < n && (ones > k || s[i] == '0')) {
                ones = s[i] == '1' ? ones - 1 : ones;
                i++;
            }
            if (ones == k) {
                change = true;
                string str = s.substr(i, j - i + 1);
                if (j - i + 1 < len) {
                    ans = str;
                    len = j - i + 1;
                } else if (j - i + 1 == len && str < ans)
                    ans = str;
            }
        }
        return change ? ans : "";
    }
};