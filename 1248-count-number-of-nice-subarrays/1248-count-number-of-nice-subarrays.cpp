class Solution {
public:
int countNiceSubarrays(vector<int> &array, int k)
{
    int i = 0, j = 0, numberOfNiceSubarrays = 0, numberOfOddNumbers = 0;
    while (j < array.size())
    {
        if (array[j] & 1 == 1)
            numberOfOddNumbers++;
        while (numberOfOddNumbers > k && i <= j)
        {
            if (array[i] & 1 == 1)
                numberOfOddNumbers--;
            i++;
        }
        numberOfNiceSubarrays += j - i + 1;
        j++;
    }
    return numberOfNiceSubarrays;
}
    int numberOfSubarrays(vector<int>& array, int k) {
         return countNiceSubarrays(array, k) - countNiceSubarrays(array, k - 1); 
    }
};