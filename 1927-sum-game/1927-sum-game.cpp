class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumDiff = 0;
        int quesDiff = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                quesDiff++;
            else
                sumDiff += (num[i] - '0');
            if (num[n / 2 + i] == '?')
                quesDiff--;
            else
                sumDiff -= (num[n / 2 + i] - '0');
        }
        if (sumDiff > 0 && quesDiff > 0 || sumDiff < 0 && quesDiff < 0)
            return true;
        if (quesDiff == 0)
            return sumDiff != 0;
        quesDiff = abs(quesDiff);
        sumDiff = abs(sumDiff);
        if (!(quesDiff & 1))
            return 4.5 * quesDiff != sumDiff;
        return true;
    }
};