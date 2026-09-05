class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> freq(26);
        int maxFreq = 0;
        for (char c : s) {
            freq[c - 'a']++;
            maxFreq = max(maxFreq, freq[c - 'a']);
        }
        vector<int> freq2(maxFreq + 1);
        for (int f : freq) {
            if (f != 0)
                freq2[f]++;
        }
        for (int i = maxFreq; i > 0; i--) {
            if (freq2[i] > 1) {
                ans += (freq2[i] - 1);
                freq2[i - 1] += (freq2[i] - 1);
            }
        }
        return ans;
    }
};