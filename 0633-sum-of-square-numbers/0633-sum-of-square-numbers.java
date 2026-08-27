class Solution {
   public boolean perfectSquare(long  num) {
    long  l = 0;
    long r = num;
    while (l <= r) {
        long  m = l + (r - l) / 2;
        long  sq = m * m;
        if (sq == num) return true;
        else if (sq > num) r = m - 1;
        else l = m + 1;
    }
    return false;
}
 
    public boolean judgeSquareSum(int c) {
         for (long  i = 0; i * i <= c; i++) {
        long  remain = c - i * i;
        if (perfectSquare(remain)) return true;
    }
    return false;
    }
}