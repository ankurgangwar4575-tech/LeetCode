class Solution {
public:
   double myPow(double x, int n) {
    if (n == 0) return 1;
    if (x == 0) return 0;

    long long N = n; // store in long long for safety
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double half = myPow(x, N / 2);
    if (N % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

};