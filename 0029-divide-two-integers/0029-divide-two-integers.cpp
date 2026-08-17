class Solution {
public:
   int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    if (dividend == INT32_MIN && divisor == -1)
        return INT32_MAX;
    bool sign = true;
    if (dividend > 0 && divisor < 0)
        sign = false;
    if (dividend < 0 && divisor > 0)
        sign = false ;
   
    int ans = 0;
    long long dvd=abs((long long)dividend),dvs=abs((long long)divisor);
    while (dvd >= dvs)
    {
        int i = 0;
        while ((dvs << (i + 1)) <= dvd)
            i++;
        ans += 1 << i;
        dvd = dvd - (dvs << i);
    }
    return sign ?(long long) ans : -1 *(long long) ans;
}
};