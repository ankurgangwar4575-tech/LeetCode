class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0 && right == 0)
            return 0;
        int leftBits = 0, rightBits = 0;
        if (left != 0)
            leftBits = 32 - __builtin_clz(left);
        if (right != 0)
            rightBits = 32 - __builtin_clz(right);
        if (leftBits != rightBits)
            return 0;
        int ans = 0;
        for (int b = leftBits - 1; b >= 0; b--) {
            int l = left >> b & 1, r = right >> b & 1;
            if (!l && r || l && !r)
                break;
            if (l && r)
                ans += 1 << b;
        }
        return ans;
    }
};