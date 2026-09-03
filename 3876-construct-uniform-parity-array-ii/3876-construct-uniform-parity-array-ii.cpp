class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even = 0, odd = 0;
        for (int& el : nums1) {
            if (el % 2 == 0)
                even++;
            else
                odd++;
        }
        if (n == even || n == odd)
            return true;
        int mini = *min_element(nums1.begin(), nums1.end());
        if (mini % 2 == 0) {
            for (int& el : nums1) {
                if (el % 2 == 1)
                    return false;
            }
            return true;
        }
        return true;
    }
};