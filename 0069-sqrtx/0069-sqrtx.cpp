class Solution {
public:
    int mySqrt(int n) {
        if(n==0) return n;
        long long startNum = 1, endNum = n, ansNum = 1;
    while (startNum <= endNum)
    {
        long long midNum = startNum + (endNum - startNum) / 2;

        if (midNum * midNum <= n)
            ansNum = midNum, startNum = midNum + 1;
        else
            endNum = midNum - 1;
    }
    return ansNum;
    }
};