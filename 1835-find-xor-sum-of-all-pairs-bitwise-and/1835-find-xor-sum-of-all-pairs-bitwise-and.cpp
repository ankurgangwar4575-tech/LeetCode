class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for (int b = 0; b < 30; b++) {
            long long setBits1 = 0, setBits2 = 0;
            for (int x : arr1) {
                if (x >> b & 1)
                    setBits1++;
            }
            for (int x : arr2) {
                if (x >> b & 1)
                    setBits2++;
            }
            long long pairsPossible = (long long)(setBits1 * setBits2);
            if (pairsPossible & 1)
                ans += 1 << b;
        }
        return ans;
    }
};