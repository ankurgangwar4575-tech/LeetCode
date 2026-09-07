class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (c >> i & 1 && !(a >> i & 1) && !(b >> i & 1))
                ans++;
            else if (!(c >> i & 1) && a >> i & 1 && b >> i & 1)
                ans += 2;
            else if (!(c >> i & 1) && (a >> i & 1 || b >> i & 1))
                ans++;
        }
        return ans;
    }
};