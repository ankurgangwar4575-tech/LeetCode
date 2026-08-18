class Solution {
public:
    int smallestNumber(int n, int t) {
        while (solve(n) % t != 0)
            n++;
        return n;
    }

private:
    int solve(int n) {
        int res = 1;
        while (n > 0) {
            res *= (n % 10);
            n /= 10;
        }
        return res;
    }
};